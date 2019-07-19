/*
* Copyright (C) 2019 University of Bologna
*
* Author: Capotondi, Alessandro, University of Bologna
*         <alessandro.capotondi@unibo.it>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "string.h"
#include "app_x-cube-ai.h"
#include "usr_mobilenet.h"

/******** Cycle counter defines  **********/
#if MOBILENET_PROFILE
volatile unsigned int *DWT_CYCCNT = (volatile unsigned int *)0xE0001004; // Cycle Counter Register
volatile unsigned int *DWT_CONTROL= (volatile unsigned int *)0xE0001000; // Counter Control Register
volatile unsigned int *SCB_DEMCR  = (volatile unsigned int *)0xE000EDFC;

long long usr_nr_nb_run = 0LL;
long long usr_cycle_counter = 0LL;
#endif

/* Network Handle */
ai_handle mobilenet_network = AI_HANDLE_NULL;

/* Global buffer to handle the activations data buffer - R/W data */
AI_ALIGNED(4)
ai_u8 __attribute__((section (".Activations"))) mobilenet_activations[AI_MOBILENET_128_0_25_DATA_ACTIVATIONS_SIZE];

/* Buffers to store the tensor input/output of the network */
ai_float __attribute__((section (".IOBuffers"))) in_data[AI_MOBILENET_128_0_25_IN_1_SIZE];
ai_float __attribute__((section (".IOBuffers"))) out_data[AI_MOBILENET_128_0_25_OUT_1_SIZE];

int usr_mobilenet_init(void) {
	ai_error err;

	const ai_network_params params = {
	AI_MOBILENET_128_0_25_DATA_WEIGHTS(ai_mobilenet_128_0_25_data_weights_get()),
	AI_MOBILENET_128_0_25_DATA_ACTIVATIONS(mobilenet_activations) };

	err = ai_mobilenet_128_0_25_create(&mobilenet_network, AI_MOBILENET_128_0_25_DATA_CONFIG);
	if (err.type != AI_ERROR_NONE) {
		return -1;
	}

	if (!ai_mobilenet_128_0_25_init(mobilenet_network, &params)) {
		err = ai_mobilenet_128_0_25_get_error(mobilenet_network);
		ai_mobilenet_128_0_25_destroy(mobilenet_network);
		mobilenet_network = AI_HANDLE_NULL;
		return -1;
	}

	return 0;
}

void usr_mobilenet_deinit(void) {
	if (mobilenet_network != AI_HANDLE_NULL)
		ai_mobilenet_128_0_25_destroy(mobilenet_network);
	mobilenet_network = AI_HANDLE_NULL;
}

int usr_mobilenet_run(const ai_float *in_data, ai_float *out_data) {
	ai_i32 nbatch;
	ai_error err;

	/* AI buffer handlers */
	ai_buffer ai_input[AI_MOBILENET_128_0_25_IN_NUM] = { AI_MOBILENET_128_0_25_IN };
	ai_buffer ai_output[AI_MOBILENET_128_0_25_OUT_NUM] = { AI_MOBILENET_128_0_25_OUT };

	/* Parameters checking */
	if (!in_data || !out_data || !mobilenet_network)
		return -1;

	/* Initialize input/output buffer handlers */
	ai_input[0].n_batches = 1;
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].n_batches = 1;
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	/* Perform the inference */
	nbatch = ai_mobilenet_128_0_25_run(mobilenet_network, &ai_input[0], &ai_output[0]);

	if (nbatch != 1) {
		err = ai_mobilenet_128_0_25_get_error(mobilenet_network);
		// ...
		return -1;
	}

	return 0;
}
