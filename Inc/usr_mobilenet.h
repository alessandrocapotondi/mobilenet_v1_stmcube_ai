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

#ifndef USR_MOBILENET_H_
#define USR_MOBILENET_H_

/******** Cycle counter defines  **********/
#define MOBILENET_PROFILE 1

#if MOBILENET_PROFILE
extern volatile unsigned int *DWT_CYCCNT;
extern volatile unsigned int *DWT_CONTROL;
extern volatile unsigned int *SCB_DEMCR;
extern long long usr_nr_nb_run;
extern long long usr_cycle_counter;

#define USR_MEM_BARRIER() \
	do { \
		asm volatile("" ::: "memory");\
	} while (0)

#define USR_CC_ENABLE() \
  do { \
	asm volatile("" ::: "memory"); \
	*SCB_DEMCR = *SCB_DEMCR | 0x01000000;\
	*DWT_CYCCNT = 0; \
	*DWT_CONTROL = *DWT_CONTROL | 1; \
	asm volatile("" ::: "memory"); \
  } while (0)

#define USR_CC_RESET() \
  do { \
	asm volatile("" ::: "memory"); \
	*DWT_CYCCNT = 0; \
	asm volatile("" ::: "memory"); \
  } while (0)

#define USR_GET_CC_TIMESTAMP_(x) \
  do { \
	asm volatile("" ::: "memory"); \
	x = (*(volatile unsigned int *) DWT_CYCCNT); \
	asm volatile("" ::: "memory"); \
  } while (0)

#define USR_GET_CC_ACC_TIMESTAMP(acc) \
  do { \
	asm volatile("" ::: "memory"); \
	acc += (*(volatile unsigned int *) DWT_CYCCNT); \
	asm volatile("" ::: "memory"); \
  } while (0)
#else
#define USR_MEM_BARRIER()
#define USR_CC_ENABLE()
#define USR_CC_RESET()
#define USR_GET_CC_TIMESTAMP(x)
#endif

/* Network Handle */
extern ai_handle mobilenet_network;

/* Global buffer to handle the activations data buffer - R/W data */
extern ai_u8 mobilenet_activations[];

/* Buffers to store the tensor input/output of the network */
extern ai_float in_data[];
extern ai_float out_data[];

int usr_mobilenet_init(void);
void usr_mobilenet_deinit(void);
int usr_mobilenet_run(const ai_float *in_data, ai_float *out_data);

#endif /* USR_MOBILENET_H_ */
