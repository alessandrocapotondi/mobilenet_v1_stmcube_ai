/**
  ******************************************************************************
  * @file    mobilenet_128_0_25.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Jul 19 13:56:30 2019
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */



#include "mobilenet_128_0_25.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 4
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0

#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_mobilenet_128_0_25
 
#undef AI_MOBILENET_128_0_25_MODEL_SIGNATURE
#define AI_MOBILENET_128_0_25_MODEL_SIGNATURE     "35ae6a7b66552cf07dbc4cf2642b4e8f"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Jul 19 13:56:30 2019"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_MOBILENET_128_0_25_N_BATCHES
#define AI_MOBILENET_128_0_25_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv_pw_13_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv_preds_bias_array;   /* Array #1 */
AI_STATIC ai_array conv_preds_weights_array;   /* Array #2 */
AI_STATIC ai_array conv_pw_13_bias_array;   /* Array #3 */
AI_STATIC ai_array conv_pw_13_weights_array;   /* Array #4 */
AI_STATIC ai_array conv_dw_13_bias_array;   /* Array #5 */
AI_STATIC ai_array conv_dw_13_weights_array;   /* Array #6 */
AI_STATIC ai_array conv_pw_12_bias_array;   /* Array #7 */
AI_STATIC ai_array conv_pw_12_weights_array;   /* Array #8 */
AI_STATIC ai_array conv_dw_12_bias_array;   /* Array #9 */
AI_STATIC ai_array conv_dw_12_weights_array;   /* Array #10 */
AI_STATIC ai_array conv_pw_11_bias_array;   /* Array #11 */
AI_STATIC ai_array conv_pw_11_weights_array;   /* Array #12 */
AI_STATIC ai_array conv_dw_11_bias_array;   /* Array #13 */
AI_STATIC ai_array conv_dw_11_weights_array;   /* Array #14 */
AI_STATIC ai_array conv_pw_10_bias_array;   /* Array #15 */
AI_STATIC ai_array conv_pw_10_weights_array;   /* Array #16 */
AI_STATIC ai_array conv_dw_10_bias_array;   /* Array #17 */
AI_STATIC ai_array conv_dw_10_weights_array;   /* Array #18 */
AI_STATIC ai_array conv_pw_9_bias_array;   /* Array #19 */
AI_STATIC ai_array conv_pw_9_weights_array;   /* Array #20 */
AI_STATIC ai_array conv_dw_9_bias_array;   /* Array #21 */
AI_STATIC ai_array conv_dw_9_weights_array;   /* Array #22 */
AI_STATIC ai_array conv_pw_8_bias_array;   /* Array #23 */
AI_STATIC ai_array conv_pw_8_weights_array;   /* Array #24 */
AI_STATIC ai_array conv_dw_8_bias_array;   /* Array #25 */
AI_STATIC ai_array conv_dw_8_weights_array;   /* Array #26 */
AI_STATIC ai_array conv_pw_7_bias_array;   /* Array #27 */
AI_STATIC ai_array conv_pw_7_weights_array;   /* Array #28 */
AI_STATIC ai_array conv_dw_7_bias_array;   /* Array #29 */
AI_STATIC ai_array conv_dw_7_weights_array;   /* Array #30 */
AI_STATIC ai_array conv_pw_6_bias_array;   /* Array #31 */
AI_STATIC ai_array conv_pw_6_weights_array;   /* Array #32 */
AI_STATIC ai_array conv_dw_6_bias_array;   /* Array #33 */
AI_STATIC ai_array conv_dw_6_weights_array;   /* Array #34 */
AI_STATIC ai_array conv_pw_5_bias_array;   /* Array #35 */
AI_STATIC ai_array conv_pw_5_weights_array;   /* Array #36 */
AI_STATIC ai_array conv_dw_5_bias_array;   /* Array #37 */
AI_STATIC ai_array conv_dw_5_weights_array;   /* Array #38 */
AI_STATIC ai_array conv_pw_4_bias_array;   /* Array #39 */
AI_STATIC ai_array conv_pw_4_weights_array;   /* Array #40 */
AI_STATIC ai_array conv_dw_4_bias_array;   /* Array #41 */
AI_STATIC ai_array conv_dw_4_weights_array;   /* Array #42 */
AI_STATIC ai_array conv_pw_3_bias_array;   /* Array #43 */
AI_STATIC ai_array conv_pw_3_weights_array;   /* Array #44 */
AI_STATIC ai_array conv_dw_3_bias_array;   /* Array #45 */
AI_STATIC ai_array conv_dw_3_weights_array;   /* Array #46 */
AI_STATIC ai_array conv_pw_2_bias_array;   /* Array #47 */
AI_STATIC ai_array conv_pw_2_weights_array;   /* Array #48 */
AI_STATIC ai_array conv_dw_2_bias_array;   /* Array #49 */
AI_STATIC ai_array conv_dw_2_weights_array;   /* Array #50 */
AI_STATIC ai_array conv_pw_1_bias_array;   /* Array #51 */
AI_STATIC ai_array conv_pw_1_weights_array;   /* Array #52 */
AI_STATIC ai_array conv_dw_1_bias_array;   /* Array #53 */
AI_STATIC ai_array conv_dw_1_weights_array;   /* Array #54 */
AI_STATIC ai_array conv1_bias_array;   /* Array #55 */
AI_STATIC ai_array conv1_weights_array;   /* Array #56 */
AI_STATIC ai_array input_3_output_array;   /* Array #57 */
AI_STATIC ai_array conv1_output_array;   /* Array #58 */
AI_STATIC ai_array conv_dw_1_output_array;   /* Array #59 */
AI_STATIC ai_array conv_pw_1_output_array;   /* Array #60 */
AI_STATIC ai_array conv_dw_2_output_array;   /* Array #61 */
AI_STATIC ai_array conv_pw_2_output_array;   /* Array #62 */
AI_STATIC ai_array conv_dw_3_output_array;   /* Array #63 */
AI_STATIC ai_array conv_pw_3_output_array;   /* Array #64 */
AI_STATIC ai_array conv_dw_4_output_array;   /* Array #65 */
AI_STATIC ai_array conv_pw_4_output_array;   /* Array #66 */
AI_STATIC ai_array conv_dw_5_output_array;   /* Array #67 */
AI_STATIC ai_array conv_pw_5_output_array;   /* Array #68 */
AI_STATIC ai_array conv_dw_6_output_array;   /* Array #69 */
AI_STATIC ai_array conv_pw_6_output_array;   /* Array #70 */
AI_STATIC ai_array conv_dw_7_output_array;   /* Array #71 */
AI_STATIC ai_array conv_pw_7_output_array;   /* Array #72 */
AI_STATIC ai_array conv_dw_8_output_array;   /* Array #73 */
AI_STATIC ai_array conv_pw_8_output_array;   /* Array #74 */
AI_STATIC ai_array conv_dw_9_output_array;   /* Array #75 */
AI_STATIC ai_array conv_pw_9_output_array;   /* Array #76 */
AI_STATIC ai_array conv_dw_10_output_array;   /* Array #77 */
AI_STATIC ai_array conv_pw_10_output_array;   /* Array #78 */
AI_STATIC ai_array conv_dw_11_output_array;   /* Array #79 */
AI_STATIC ai_array conv_pw_11_output_array;   /* Array #80 */
AI_STATIC ai_array conv_dw_12_output_array;   /* Array #81 */
AI_STATIC ai_array conv_pw_12_output_array;   /* Array #82 */
AI_STATIC ai_array conv_dw_13_output_array;   /* Array #83 */
AI_STATIC ai_array conv_pw_13_output_array;   /* Array #84 */
AI_STATIC ai_array conv_preds_output_array;   /* Array #85 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv_pw_13_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv_preds_bias;   /* Tensor #1 */
AI_STATIC ai_tensor conv_preds_weights;   /* Tensor #2 */
AI_STATIC ai_tensor conv_pw_13_bias;   /* Tensor #3 */
AI_STATIC ai_tensor conv_pw_13_weights;   /* Tensor #4 */
AI_STATIC ai_tensor conv_dw_13_bias;   /* Tensor #5 */
AI_STATIC ai_tensor conv_dw_13_weights;   /* Tensor #6 */
AI_STATIC ai_tensor conv_pw_12_bias;   /* Tensor #7 */
AI_STATIC ai_tensor conv_pw_12_weights;   /* Tensor #8 */
AI_STATIC ai_tensor conv_dw_12_bias;   /* Tensor #9 */
AI_STATIC ai_tensor conv_dw_12_weights;   /* Tensor #10 */
AI_STATIC ai_tensor conv_pw_11_bias;   /* Tensor #11 */
AI_STATIC ai_tensor conv_pw_11_weights;   /* Tensor #12 */
AI_STATIC ai_tensor conv_dw_11_bias;   /* Tensor #13 */
AI_STATIC ai_tensor conv_dw_11_weights;   /* Tensor #14 */
AI_STATIC ai_tensor conv_pw_10_bias;   /* Tensor #15 */
AI_STATIC ai_tensor conv_pw_10_weights;   /* Tensor #16 */
AI_STATIC ai_tensor conv_dw_10_bias;   /* Tensor #17 */
AI_STATIC ai_tensor conv_dw_10_weights;   /* Tensor #18 */
AI_STATIC ai_tensor conv_pw_9_bias;   /* Tensor #19 */
AI_STATIC ai_tensor conv_pw_9_weights;   /* Tensor #20 */
AI_STATIC ai_tensor conv_dw_9_bias;   /* Tensor #21 */
AI_STATIC ai_tensor conv_dw_9_weights;   /* Tensor #22 */
AI_STATIC ai_tensor conv_pw_8_bias;   /* Tensor #23 */
AI_STATIC ai_tensor conv_pw_8_weights;   /* Tensor #24 */
AI_STATIC ai_tensor conv_dw_8_bias;   /* Tensor #25 */
AI_STATIC ai_tensor conv_dw_8_weights;   /* Tensor #26 */
AI_STATIC ai_tensor conv_pw_7_bias;   /* Tensor #27 */
AI_STATIC ai_tensor conv_pw_7_weights;   /* Tensor #28 */
AI_STATIC ai_tensor conv_dw_7_bias;   /* Tensor #29 */
AI_STATIC ai_tensor conv_dw_7_weights;   /* Tensor #30 */
AI_STATIC ai_tensor conv_pw_6_bias;   /* Tensor #31 */
AI_STATIC ai_tensor conv_pw_6_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv_dw_6_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv_dw_6_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv_pw_5_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv_pw_5_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv_dw_5_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv_dw_5_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv_pw_4_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv_pw_4_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv_dw_4_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv_dw_4_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv_pw_3_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv_pw_3_weights;   /* Tensor #44 */
AI_STATIC ai_tensor conv_dw_3_bias;   /* Tensor #45 */
AI_STATIC ai_tensor conv_dw_3_weights;   /* Tensor #46 */
AI_STATIC ai_tensor conv_pw_2_bias;   /* Tensor #47 */
AI_STATIC ai_tensor conv_pw_2_weights;   /* Tensor #48 */
AI_STATIC ai_tensor conv_dw_2_bias;   /* Tensor #49 */
AI_STATIC ai_tensor conv_dw_2_weights;   /* Tensor #50 */
AI_STATIC ai_tensor conv_pw_1_bias;   /* Tensor #51 */
AI_STATIC ai_tensor conv_pw_1_weights;   /* Tensor #52 */
AI_STATIC ai_tensor conv_dw_1_bias;   /* Tensor #53 */
AI_STATIC ai_tensor conv_dw_1_weights;   /* Tensor #54 */
AI_STATIC ai_tensor conv1_bias;   /* Tensor #55 */
AI_STATIC ai_tensor conv1_weights;   /* Tensor #56 */
AI_STATIC ai_tensor input_3_output;   /* Tensor #57 */
AI_STATIC ai_tensor conv1_output;   /* Tensor #58 */
AI_STATIC ai_tensor conv_dw_1_output;   /* Tensor #59 */
AI_STATIC ai_tensor conv_pw_1_output;   /* Tensor #60 */
AI_STATIC ai_tensor conv_dw_2_output;   /* Tensor #61 */
AI_STATIC ai_tensor conv_pw_2_output;   /* Tensor #62 */
AI_STATIC ai_tensor conv_dw_3_output;   /* Tensor #63 */
AI_STATIC ai_tensor conv_pw_3_output;   /* Tensor #64 */
AI_STATIC ai_tensor conv_dw_4_output;   /* Tensor #65 */
AI_STATIC ai_tensor conv_pw_4_output;   /* Tensor #66 */
AI_STATIC ai_tensor conv_dw_5_output;   /* Tensor #67 */
AI_STATIC ai_tensor conv_pw_5_output;   /* Tensor #68 */
AI_STATIC ai_tensor conv_dw_6_output;   /* Tensor #69 */
AI_STATIC ai_tensor conv_pw_6_output;   /* Tensor #70 */
AI_STATIC ai_tensor conv_dw_7_output;   /* Tensor #71 */
AI_STATIC ai_tensor conv_pw_7_output;   /* Tensor #72 */
AI_STATIC ai_tensor conv_dw_8_output;   /* Tensor #73 */
AI_STATIC ai_tensor conv_pw_8_output;   /* Tensor #74 */
AI_STATIC ai_tensor conv_dw_9_output;   /* Tensor #75 */
AI_STATIC ai_tensor conv_pw_9_output;   /* Tensor #76 */
AI_STATIC ai_tensor conv_dw_10_output;   /* Tensor #77 */
AI_STATIC ai_tensor conv_pw_10_output;   /* Tensor #78 */
AI_STATIC ai_tensor conv_dw_11_output;   /* Tensor #79 */
AI_STATIC ai_tensor conv_pw_11_output;   /* Tensor #80 */
AI_STATIC ai_tensor conv_dw_12_output;   /* Tensor #81 */
AI_STATIC ai_tensor conv_pw_12_output;   /* Tensor #82 */
AI_STATIC ai_tensor conv_dw_13_output;   /* Tensor #83 */
AI_STATIC ai_tensor conv_pw_13_output;   /* Tensor #84 */
AI_STATIC ai_tensor conv_preds_output;   /* Tensor #85 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv_dw_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv_pw_1_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv_dw_2_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv_pw_2_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv_dw_3_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv_pw_3_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv_dw_4_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv_pw_4_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv_dw_5_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv_pw_5_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv_dw_6_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv_pw_6_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv_dw_7_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv_pw_7_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv_dw_8_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv_pw_8_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv_dw_9_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv_pw_9_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv_dw_10_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv_pw_10_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv_dw_11_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv_pw_11_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv_dw_12_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv_pw_12_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv_dw_13_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv_pw_13_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv_preds_chain;   /* Chain #27 */


/**  Subgraph network operator tensor chain declarations  *********************/


/**  Subgraph network operator declarations  *********************************/


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv1_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv_dw_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv_pw_1_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv_dw_2_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv_pw_2_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv_dw_3_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv_pw_3_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv_dw_4_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv_pw_4_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv_dw_5_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv_pw_5_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv_dw_6_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv_pw_6_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv_dw_7_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv_pw_7_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv_dw_8_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv_pw_8_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv_dw_9_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv_pw_9_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv_dw_10_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv_pw_10_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv_dw_11_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv_pw_11_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv_dw_12_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv_pw_12_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv_dw_13_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d_nl_pool conv_pw_13_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv_preds_layer; /* Layer #27 */


/**  Array declarations section  **********************************************/
AI_ARRAY_OBJ_DECLARE(
  conv_pw_13_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_preds_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1000,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_preds_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256000,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 65536,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 216,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  input_3_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 49152,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 65536,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_dw_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_pw_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256,
  AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
  conv_preds_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1000,
  AI_STATIC)


/**  Tensor declarations section  *********************************************/
AI_TENSOR_OBJ_DECLARE(
  conv_pw_13_scratch0,
  AI_SHAPE_INIT(4, 4, 256, 1),
  AI_STRIDE_INIT(4096, 1024, 4, 4),
  &conv_pw_13_scratch0_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_preds_bias,
  AI_SHAPE_INIT(1, 1, 1000, 1),
  AI_STRIDE_INIT(4000, 4000, 4, 4),
  &conv_preds_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_preds_weights,
  AI_SHAPE_INIT(1000, 1, 1, 256),
  AI_STRIDE_INIT(1024, 1024, 1024, 4),
  &conv_preds_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_13_bias,
  AI_SHAPE_INIT(1, 1, 256, 1),
  AI_STRIDE_INIT(1024, 1024, 4, 4),
  &conv_pw_13_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_13_weights,
  AI_SHAPE_INIT(256, 1, 1, 256),
  AI_STRIDE_INIT(1024, 1024, 1024, 4),
  &conv_pw_13_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_13_bias,
  AI_SHAPE_INIT(1, 1, 256, 1),
  AI_STRIDE_INIT(1024, 1024, 4, 4),
  &conv_dw_13_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_13_weights,
  AI_SHAPE_INIT(256, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_13_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_12_bias,
  AI_SHAPE_INIT(1, 1, 256, 1),
  AI_STRIDE_INIT(1024, 1024, 4, 4),
  &conv_pw_12_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_12_weights,
  AI_SHAPE_INIT(256, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_12_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_12_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_12_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_12_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_12_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_11_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_weights,
  AI_SHAPE_INIT(128, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_11_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_11_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_11_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_10_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_weights,
  AI_SHAPE_INIT(128, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_10_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_10_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_10_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_9_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_weights,
  AI_SHAPE_INIT(128, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_9_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_9_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_9_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_8_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_weights,
  AI_SHAPE_INIT(128, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_8_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_8_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_8_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_7_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_weights,
  AI_SHAPE_INIT(128, 1, 1, 128),
  AI_STRIDE_INIT(512, 512, 512, 4),
  &conv_pw_7_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_dw_7_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_weights,
  AI_SHAPE_INIT(128, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_7_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_bias,
  AI_SHAPE_INIT(1, 1, 128, 1),
  AI_STRIDE_INIT(512, 512, 4, 4),
  &conv_pw_6_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_weights,
  AI_SHAPE_INIT(128, 1, 1, 64),
  AI_STRIDE_INIT(256, 256, 256, 4),
  &conv_pw_6_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_bias,
  AI_SHAPE_INIT(1, 1, 64, 1),
  AI_STRIDE_INIT(256, 256, 4, 4),
  &conv_dw_6_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_weights,
  AI_SHAPE_INIT(64, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_6_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_bias,
  AI_SHAPE_INIT(1, 1, 64, 1),
  AI_STRIDE_INIT(256, 256, 4, 4),
  &conv_pw_5_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_weights,
  AI_SHAPE_INIT(64, 1, 1, 64),
  AI_STRIDE_INIT(256, 256, 256, 4),
  &conv_pw_5_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_bias,
  AI_SHAPE_INIT(1, 1, 64, 1),
  AI_STRIDE_INIT(256, 256, 4, 4),
  &conv_dw_5_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_weights,
  AI_SHAPE_INIT(64, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_5_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_bias,
  AI_SHAPE_INIT(1, 1, 64, 1),
  AI_STRIDE_INIT(256, 256, 4, 4),
  &conv_pw_4_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_weights,
  AI_SHAPE_INIT(64, 1, 1, 32),
  AI_STRIDE_INIT(128, 128, 128, 4),
  &conv_pw_4_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_bias,
  AI_SHAPE_INIT(1, 1, 32, 1),
  AI_STRIDE_INIT(128, 128, 4, 4),
  &conv_dw_4_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_weights,
  AI_SHAPE_INIT(32, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_4_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_bias,
  AI_SHAPE_INIT(1, 1, 32, 1),
  AI_STRIDE_INIT(128, 128, 4, 4),
  &conv_pw_3_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_weights,
  AI_SHAPE_INIT(32, 1, 1, 32),
  AI_STRIDE_INIT(128, 128, 128, 4),
  &conv_pw_3_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_bias,
  AI_SHAPE_INIT(1, 1, 32, 1),
  AI_STRIDE_INIT(128, 128, 4, 4),
  &conv_dw_3_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_weights,
  AI_SHAPE_INIT(32, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_3_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_bias,
  AI_SHAPE_INIT(1, 1, 32, 1),
  AI_STRIDE_INIT(128, 128, 4, 4),
  &conv_pw_2_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_weights,
  AI_SHAPE_INIT(32, 1, 1, 16),
  AI_STRIDE_INIT(64, 64, 64, 4),
  &conv_pw_2_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_bias,
  AI_SHAPE_INIT(1, 1, 16, 1),
  AI_STRIDE_INIT(64, 64, 4, 4),
  &conv_dw_2_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_weights,
  AI_SHAPE_INIT(16, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_2_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_bias,
  AI_SHAPE_INIT(1, 1, 16, 1),
  AI_STRIDE_INIT(64, 64, 4, 4),
  &conv_pw_1_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_weights,
  AI_SHAPE_INIT(16, 1, 1, 8),
  AI_STRIDE_INIT(32, 32, 32, 4),
  &conv_pw_1_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_bias,
  AI_SHAPE_INIT(1, 1, 8, 1),
  AI_STRIDE_INIT(32, 32, 4, 4),
  &conv_dw_1_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_weights,
  AI_SHAPE_INIT(8, 3, 3, 1),
  AI_STRIDE_INIT(36, 12, 4, 4),
  &conv_dw_1_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv1_bias,
  AI_SHAPE_INIT(1, 1, 8, 1),
  AI_STRIDE_INIT(32, 32, 4, 4),
  &conv1_bias_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv1_weights,
  AI_SHAPE_INIT(8, 3, 3, 3),
  AI_STRIDE_INIT(108, 36, 12, 4),
  &conv1_weights_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  input_3_output,
  AI_SHAPE_INIT(128, 128, 3, 1),
  AI_STRIDE_INIT(1536, 12, 4, 4),
  &input_3_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv1_output,
  AI_SHAPE_INIT(64, 64, 8, 1),
  AI_STRIDE_INIT(2048, 32, 4, 4),
  &conv1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_output,
  AI_SHAPE_INIT(64, 64, 8, 1),
  AI_STRIDE_INIT(2048, 32, 4, 4),
  &conv_dw_1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_output,
  AI_SHAPE_INIT(64, 64, 16, 1),
  AI_STRIDE_INIT(4096, 64, 4, 4),
  &conv_pw_1_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_output,
  AI_SHAPE_INIT(32, 32, 16, 1),
  AI_STRIDE_INIT(2048, 64, 4, 4),
  &conv_dw_2_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_output,
  AI_SHAPE_INIT(32, 32, 32, 1),
  AI_STRIDE_INIT(4096, 128, 4, 4),
  &conv_pw_2_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_output,
  AI_SHAPE_INIT(32, 32, 32, 1),
  AI_STRIDE_INIT(4096, 128, 4, 4),
  &conv_dw_3_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_output,
  AI_SHAPE_INIT(32, 32, 32, 1),
  AI_STRIDE_INIT(4096, 128, 4, 4),
  &conv_pw_3_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_output,
  AI_SHAPE_INIT(16, 16, 32, 1),
  AI_STRIDE_INIT(2048, 128, 4, 4),
  &conv_dw_4_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_output,
  AI_SHAPE_INIT(16, 16, 64, 1),
  AI_STRIDE_INIT(4096, 256, 4, 4),
  &conv_pw_4_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_output,
  AI_SHAPE_INIT(16, 16, 64, 1),
  AI_STRIDE_INIT(4096, 256, 4, 4),
  &conv_dw_5_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_output,
  AI_SHAPE_INIT(16, 16, 64, 1),
  AI_STRIDE_INIT(4096, 256, 4, 4),
  &conv_pw_5_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_output,
  AI_SHAPE_INIT(8, 8, 64, 1),
  AI_STRIDE_INIT(2048, 256, 4, 4),
  &conv_dw_6_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_6_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_dw_7_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_7_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_dw_8_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_8_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_dw_9_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_9_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_dw_10_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_10_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_dw_11_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_output,
  AI_SHAPE_INIT(8, 8, 128, 1),
  AI_STRIDE_INIT(4096, 512, 4, 4),
  &conv_pw_11_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_12_output,
  AI_SHAPE_INIT(4, 4, 128, 1),
  AI_STRIDE_INIT(2048, 512, 4, 4),
  &conv_dw_12_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_12_output,
  AI_SHAPE_INIT(4, 4, 256, 1),
  AI_STRIDE_INIT(4096, 1024, 4, 4),
  &conv_pw_12_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_dw_13_output,
  AI_SHAPE_INIT(4, 4, 256, 1),
  AI_STRIDE_INIT(4096, 1024, 4, 4),
  &conv_dw_13_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_pw_13_output,
  AI_SHAPE_INIT(1, 1, 256, 1),
  AI_STRIDE_INIT(1024, 1024, 4, 4),
  &conv_pw_13_output_array,
  AI_STATIC)
AI_TENSOR_OBJ_DECLARE(
  conv_preds_output,
  AI_SHAPE_INIT(1, 1, 1000, 1),
  AI_STRIDE_INIT(4000, 4000, 4, 4),
  &conv_preds_output_array,
  AI_STATIC)


/**  Layer declarations section  **********************************************/




AI_ARRAY_OBJ_DECLARE_STATIC(conv1_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&input_3_output),
  AI_TENSOR_LIST_ENTRY(&conv1_output),
  AI_TENSOR_LIST_ENTRY(&conv1_weights, &conv1_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_1_layer, AI_STATIC,
  .tensors = &conv1_chain, 
  .groups = 1, 
  .nl_params = &conv1_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_1_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv1_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_1_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_1_weights, &conv_dw_1_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_1_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_1_layer, AI_STATIC,
  .tensors = &conv_dw_1_chain, 
  .groups = 8, 
  .nl_params = &conv_dw_1_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_1_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_1_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_1_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_1_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_1_weights, &conv_pw_1_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_1_layer, 8,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_2_layer, AI_STATIC,
  .tensors = &conv_pw_1_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_1_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_2_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_2_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_1_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_2_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_2_weights, &conv_dw_2_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_2_layer, 12,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_2_layer, AI_STATIC,
  .tensors = &conv_dw_2_chain, 
  .groups = 16, 
  .nl_params = &conv_dw_2_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_2_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_2_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_2_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_2_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_2_weights, &conv_pw_2_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_2_layer, 15,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_3_layer, AI_STATIC,
  .tensors = &conv_pw_2_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_2_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_3_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_3_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_2_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_3_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_3_weights, &conv_dw_3_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_3_layer, 18,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_3_layer, AI_STATIC,
  .tensors = &conv_dw_3_chain, 
  .groups = 32, 
  .nl_params = &conv_dw_3_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_3_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_3_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_3_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_3_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_3_weights, &conv_pw_3_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_3_layer, 21,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_4_layer, AI_STATIC,
  .tensors = &conv_pw_3_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_3_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_4_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_4_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_3_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_4_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_4_weights, &conv_dw_4_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_4_layer, 25,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_4_layer, AI_STATIC,
  .tensors = &conv_dw_4_chain, 
  .groups = 32, 
  .nl_params = &conv_dw_4_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_4_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_4_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_4_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_4_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_4_weights, &conv_pw_4_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_4_layer, 28,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_5_layer, AI_STATIC,
  .tensors = &conv_pw_4_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_4_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_5_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_5_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_4_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_5_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_5_weights, &conv_dw_5_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_5_layer, 31,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_5_layer, AI_STATIC,
  .tensors = &conv_dw_5_chain, 
  .groups = 64, 
  .nl_params = &conv_dw_5_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_5_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_5_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_5_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_5_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_5_weights, &conv_pw_5_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_5_layer, 34,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_6_layer, AI_STATIC,
  .tensors = &conv_pw_5_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_5_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_6_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_6_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_5_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_6_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_6_weights, &conv_dw_6_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_6_layer, 38,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_6_layer, AI_STATIC,
  .tensors = &conv_dw_6_chain, 
  .groups = 64, 
  .nl_params = &conv_dw_6_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_6_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_6_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_6_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_6_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_6_weights, &conv_pw_6_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_6_layer, 41,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_7_layer, AI_STATIC,
  .tensors = &conv_pw_6_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_6_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_7_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_7_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_6_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_7_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_7_weights, &conv_dw_7_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_7_layer, 44,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_7_layer, AI_STATIC,
  .tensors = &conv_dw_7_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_7_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_7_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_7_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_7_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_7_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_7_weights, &conv_pw_7_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_7_layer, 47,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_8_layer, AI_STATIC,
  .tensors = &conv_pw_7_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_7_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_8_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_8_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_7_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_8_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_8_weights, &conv_dw_8_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_8_layer, 50,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_8_layer, AI_STATIC,
  .tensors = &conv_dw_8_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_8_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_8_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_8_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_8_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_8_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_8_weights, &conv_pw_8_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_8_layer, 53,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_9_layer, AI_STATIC,
  .tensors = &conv_pw_8_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_8_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_9_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_9_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_8_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_9_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_9_weights, &conv_dw_9_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_9_layer, 56,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_9_layer, AI_STATIC,
  .tensors = &conv_dw_9_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_9_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_9_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_9_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_9_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_9_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_9_weights, &conv_pw_9_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_9_layer, 59,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_10_layer, AI_STATIC,
  .tensors = &conv_pw_9_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_9_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_10_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_10_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_9_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_10_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_10_weights, &conv_dw_10_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_10_layer, 62,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_10_layer, AI_STATIC,
  .tensors = &conv_dw_10_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_10_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_10_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_10_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_10_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_10_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_10_weights, &conv_pw_10_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_10_layer, 65,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_11_layer, AI_STATIC,
  .tensors = &conv_pw_10_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_10_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_11_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_11_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_10_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_11_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_11_weights, &conv_dw_11_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_11_layer, 68,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_11_layer, AI_STATIC,
  .tensors = &conv_dw_11_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_11_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_11_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_11_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_11_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_11_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_11_weights, &conv_pw_11_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_11_layer, 71,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_12_layer, AI_STATIC,
  .tensors = &conv_pw_11_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_11_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_12_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_12_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_11_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_12_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_12_weights, &conv_dw_12_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_12_layer, 75,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_12_layer, AI_STATIC,
  .tensors = &conv_dw_12_chain, 
  .groups = 128, 
  .nl_params = &conv_dw_12_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_12_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_12_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_12_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_12_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_12_weights, &conv_pw_12_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_12_layer, 78,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_dw_13_layer, AI_STATIC,
  .tensors = &conv_pw_12_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_12_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_dw_13_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_13_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_12_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_13_output),
  AI_TENSOR_LIST_ENTRY(&conv_dw_13_weights, &conv_dw_13_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_13_layer, 81,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_pw_13_layer, AI_STATIC,
  .tensors = &conv_dw_13_chain, 
  .groups = 256, 
  .nl_params = &conv_dw_13_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 1, 1, 1, 1), 
)


AI_ARRAY_OBJ_DECLARE_STATIC(conv_pw_13_nl_params, ai_float,
  AI_ARRAY_FORMAT_FLOAT, AI_CONST, 3, 0.0, 0.0, 6.0)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_13_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_dw_13_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_13_output),
  AI_TENSOR_LIST_ENTRY(&conv_pw_13_weights, &conv_pw_13_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv_pw_13_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_13_layer, 84,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv_preds_layer, AI_STATIC,
  .tensors = &conv_pw_13_chain, 
  .groups = 1, 
  .nl_params = &conv_pw_13_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(4, 4), 
  .pool_stride = AI_SHAPE_2D_INIT(4, 4), 
  .pool_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_preds_chain, AI_STATIC_CONST, 
  AI_TENSOR_LIST_ENTRY(&conv_pw_13_output),
  AI_TENSOR_LIST_ENTRY(&conv_preds_output),
  AI_TENSOR_LIST_ENTRY(&conv_preds_weights, &conv_preds_bias, NULL),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_preds_layer, 90,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv_preds_layer, AI_STATIC,
  .tensors = &conv_preds_chain, 
  .groups = 1, 
  .nl_func = nl_func_sm_channel_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_ND_INIT(4, 0, 0, 0, 0), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1869344, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 393216, 1,
                     NULL),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_MOBILENET_128_0_25_IN_NUM, &input_3_output),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_MOBILENET_128_0_25_OUT_NUM, &conv_preds_output),
  &conv1_layer, 0)



AI_DECLARE_STATIC
ai_bool mobilenet_128_0_25_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT( activations )

  {
    /* Updating activations (byte) offsets */
    conv_pw_13_scratch0_array.data = AI_PTR(activations + 0);
    conv_pw_13_scratch0_array.data_start = AI_PTR(activations + 0);
    input_3_output_array.data = AI_PTR(NULL);
    input_3_output_array.data_start = AI_PTR(NULL);
    conv1_output_array.data = AI_PTR(activations + 0);
    conv1_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_1_output_array.data = AI_PTR(activations + 262144);
    conv_dw_1_output_array.data_start = AI_PTR(activations + 262144);
    conv_pw_1_output_array.data = AI_PTR(activations + 0);
    conv_pw_1_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_2_output_array.data = AI_PTR(activations + 262144);
    conv_dw_2_output_array.data_start = AI_PTR(activations + 262144);
    conv_pw_2_output_array.data = AI_PTR(activations + 0);
    conv_pw_2_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_3_output_array.data = AI_PTR(activations + 131072);
    conv_dw_3_output_array.data_start = AI_PTR(activations + 131072);
    conv_pw_3_output_array.data = AI_PTR(activations + 0);
    conv_pw_3_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_4_output_array.data = AI_PTR(activations + 131072);
    conv_dw_4_output_array.data_start = AI_PTR(activations + 131072);
    conv_pw_4_output_array.data = AI_PTR(activations + 0);
    conv_pw_4_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_5_output_array.data = AI_PTR(activations + 65536);
    conv_dw_5_output_array.data_start = AI_PTR(activations + 65536);
    conv_pw_5_output_array.data = AI_PTR(activations + 0);
    conv_pw_5_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_6_output_array.data = AI_PTR(activations + 65536);
    conv_dw_6_output_array.data_start = AI_PTR(activations + 65536);
    conv_pw_6_output_array.data = AI_PTR(activations + 0);
    conv_pw_6_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_7_output_array.data = AI_PTR(activations + 32768);
    conv_dw_7_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_7_output_array.data = AI_PTR(activations + 0);
    conv_pw_7_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_8_output_array.data = AI_PTR(activations + 32768);
    conv_dw_8_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_8_output_array.data = AI_PTR(activations + 0);
    conv_pw_8_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_9_output_array.data = AI_PTR(activations + 32768);
    conv_dw_9_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_9_output_array.data = AI_PTR(activations + 0);
    conv_pw_9_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_10_output_array.data = AI_PTR(activations + 32768);
    conv_dw_10_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_10_output_array.data = AI_PTR(activations + 0);
    conv_pw_10_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_11_output_array.data = AI_PTR(activations + 32768);
    conv_dw_11_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_11_output_array.data = AI_PTR(activations + 0);
    conv_pw_11_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_12_output_array.data = AI_PTR(activations + 32768);
    conv_dw_12_output_array.data_start = AI_PTR(activations + 32768);
    conv_pw_12_output_array.data = AI_PTR(activations + 0);
    conv_pw_12_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_13_output_array.data = AI_PTR(activations + 16384);
    conv_dw_13_output_array.data_start = AI_PTR(activations + 16384);
    conv_pw_13_output_array.data = AI_PTR(activations + 32768);
    conv_pw_13_output_array.data_start = AI_PTR(activations + 32768);
    conv_preds_output_array.data = AI_PTR(NULL);
    conv_preds_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool mobilenet_128_0_25_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT( weights )

  {
    /* Updating weights (byte) offsets */
    conv_preds_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_preds_bias_array.data = AI_PTR(weights + 1865344);
    conv_preds_bias_array.data_start = AI_PTR(weights + 1865344);
  conv_preds_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_preds_weights_array.data = AI_PTR(weights + 841344);
    conv_preds_weights_array.data_start = AI_PTR(weights + 841344);
  conv_pw_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_13_bias_array.data = AI_PTR(weights + 840320);
    conv_pw_13_bias_array.data_start = AI_PTR(weights + 840320);
  conv_pw_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_13_weights_array.data = AI_PTR(weights + 578176);
    conv_pw_13_weights_array.data_start = AI_PTR(weights + 578176);
  conv_dw_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_13_bias_array.data = AI_PTR(weights + 577152);
    conv_dw_13_bias_array.data_start = AI_PTR(weights + 577152);
  conv_dw_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_13_weights_array.data = AI_PTR(weights + 567936);
    conv_dw_13_weights_array.data_start = AI_PTR(weights + 567936);
  conv_pw_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_12_bias_array.data = AI_PTR(weights + 566912);
    conv_pw_12_bias_array.data_start = AI_PTR(weights + 566912);
  conv_pw_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_12_weights_array.data = AI_PTR(weights + 435840);
    conv_pw_12_weights_array.data_start = AI_PTR(weights + 435840);
  conv_dw_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_12_bias_array.data = AI_PTR(weights + 435328);
    conv_dw_12_bias_array.data_start = AI_PTR(weights + 435328);
  conv_dw_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_12_weights_array.data = AI_PTR(weights + 430720);
    conv_dw_12_weights_array.data_start = AI_PTR(weights + 430720);
  conv_pw_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_11_bias_array.data = AI_PTR(weights + 430208);
    conv_pw_11_bias_array.data_start = AI_PTR(weights + 430208);
  conv_pw_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_11_weights_array.data = AI_PTR(weights + 364672);
    conv_pw_11_weights_array.data_start = AI_PTR(weights + 364672);
  conv_dw_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_11_bias_array.data = AI_PTR(weights + 364160);
    conv_dw_11_bias_array.data_start = AI_PTR(weights + 364160);
  conv_dw_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_11_weights_array.data = AI_PTR(weights + 359552);
    conv_dw_11_weights_array.data_start = AI_PTR(weights + 359552);
  conv_pw_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_10_bias_array.data = AI_PTR(weights + 359040);
    conv_pw_10_bias_array.data_start = AI_PTR(weights + 359040);
  conv_pw_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_10_weights_array.data = AI_PTR(weights + 293504);
    conv_pw_10_weights_array.data_start = AI_PTR(weights + 293504);
  conv_dw_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_10_bias_array.data = AI_PTR(weights + 292992);
    conv_dw_10_bias_array.data_start = AI_PTR(weights + 292992);
  conv_dw_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_10_weights_array.data = AI_PTR(weights + 288384);
    conv_dw_10_weights_array.data_start = AI_PTR(weights + 288384);
  conv_pw_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_9_bias_array.data = AI_PTR(weights + 287872);
    conv_pw_9_bias_array.data_start = AI_PTR(weights + 287872);
  conv_pw_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_9_weights_array.data = AI_PTR(weights + 222336);
    conv_pw_9_weights_array.data_start = AI_PTR(weights + 222336);
  conv_dw_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_9_bias_array.data = AI_PTR(weights + 221824);
    conv_dw_9_bias_array.data_start = AI_PTR(weights + 221824);
  conv_dw_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_9_weights_array.data = AI_PTR(weights + 217216);
    conv_dw_9_weights_array.data_start = AI_PTR(weights + 217216);
  conv_pw_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_8_bias_array.data = AI_PTR(weights + 216704);
    conv_pw_8_bias_array.data_start = AI_PTR(weights + 216704);
  conv_pw_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_8_weights_array.data = AI_PTR(weights + 151168);
    conv_pw_8_weights_array.data_start = AI_PTR(weights + 151168);
  conv_dw_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_8_bias_array.data = AI_PTR(weights + 150656);
    conv_dw_8_bias_array.data_start = AI_PTR(weights + 150656);
  conv_dw_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_8_weights_array.data = AI_PTR(weights + 146048);
    conv_dw_8_weights_array.data_start = AI_PTR(weights + 146048);
  conv_pw_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_7_bias_array.data = AI_PTR(weights + 145536);
    conv_pw_7_bias_array.data_start = AI_PTR(weights + 145536);
  conv_pw_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_7_weights_array.data = AI_PTR(weights + 80000);
    conv_pw_7_weights_array.data_start = AI_PTR(weights + 80000);
  conv_dw_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_7_bias_array.data = AI_PTR(weights + 79488);
    conv_dw_7_bias_array.data_start = AI_PTR(weights + 79488);
  conv_dw_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_7_weights_array.data = AI_PTR(weights + 74880);
    conv_dw_7_weights_array.data_start = AI_PTR(weights + 74880);
  conv_pw_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_6_bias_array.data = AI_PTR(weights + 74368);
    conv_pw_6_bias_array.data_start = AI_PTR(weights + 74368);
  conv_pw_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_6_weights_array.data = AI_PTR(weights + 41600);
    conv_pw_6_weights_array.data_start = AI_PTR(weights + 41600);
  conv_dw_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_6_bias_array.data = AI_PTR(weights + 41344);
    conv_dw_6_bias_array.data_start = AI_PTR(weights + 41344);
  conv_dw_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_6_weights_array.data = AI_PTR(weights + 39040);
    conv_dw_6_weights_array.data_start = AI_PTR(weights + 39040);
  conv_pw_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_5_bias_array.data = AI_PTR(weights + 38784);
    conv_pw_5_bias_array.data_start = AI_PTR(weights + 38784);
  conv_pw_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_5_weights_array.data = AI_PTR(weights + 22400);
    conv_pw_5_weights_array.data_start = AI_PTR(weights + 22400);
  conv_dw_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_5_bias_array.data = AI_PTR(weights + 22144);
    conv_dw_5_bias_array.data_start = AI_PTR(weights + 22144);
  conv_dw_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_5_weights_array.data = AI_PTR(weights + 19840);
    conv_dw_5_weights_array.data_start = AI_PTR(weights + 19840);
  conv_pw_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_4_bias_array.data = AI_PTR(weights + 19584);
    conv_pw_4_bias_array.data_start = AI_PTR(weights + 19584);
  conv_pw_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_4_weights_array.data = AI_PTR(weights + 11392);
    conv_pw_4_weights_array.data_start = AI_PTR(weights + 11392);
  conv_dw_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_4_bias_array.data = AI_PTR(weights + 11264);
    conv_dw_4_bias_array.data_start = AI_PTR(weights + 11264);
  conv_dw_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_4_weights_array.data = AI_PTR(weights + 10112);
    conv_dw_4_weights_array.data_start = AI_PTR(weights + 10112);
  conv_pw_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_3_bias_array.data = AI_PTR(weights + 9984);
    conv_pw_3_bias_array.data_start = AI_PTR(weights + 9984);
  conv_pw_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_3_weights_array.data = AI_PTR(weights + 5888);
    conv_pw_3_weights_array.data_start = AI_PTR(weights + 5888);
  conv_dw_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_3_bias_array.data = AI_PTR(weights + 5760);
    conv_dw_3_bias_array.data_start = AI_PTR(weights + 5760);
  conv_dw_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_3_weights_array.data = AI_PTR(weights + 4608);
    conv_dw_3_weights_array.data_start = AI_PTR(weights + 4608);
  conv_pw_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_2_bias_array.data = AI_PTR(weights + 4480);
    conv_pw_2_bias_array.data_start = AI_PTR(weights + 4480);
  conv_pw_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_2_weights_array.data = AI_PTR(weights + 2432);
    conv_pw_2_weights_array.data_start = AI_PTR(weights + 2432);
  conv_dw_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_2_bias_array.data = AI_PTR(weights + 2368);
    conv_dw_2_bias_array.data_start = AI_PTR(weights + 2368);
  conv_dw_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_2_weights_array.data = AI_PTR(weights + 1792);
    conv_dw_2_weights_array.data_start = AI_PTR(weights + 1792);
  conv_pw_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_1_bias_array.data = AI_PTR(weights + 1728);
    conv_pw_1_bias_array.data_start = AI_PTR(weights + 1728);
  conv_pw_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_1_weights_array.data = AI_PTR(weights + 1216);
    conv_pw_1_weights_array.data_start = AI_PTR(weights + 1216);
  conv_dw_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_1_bias_array.data = AI_PTR(weights + 1184);
    conv_dw_1_bias_array.data_start = AI_PTR(weights + 1184);
  conv_dw_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_1_weights_array.data = AI_PTR(weights + 896);
    conv_dw_1_weights_array.data_start = AI_PTR(weights + 896);
  conv1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1_bias_array.data = AI_PTR(weights + 864);
    conv1_bias_array.data_start = AI_PTR(weights + 864);
  conv1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1_weights_array.data = AI_PTR(weights + 0);
    conv1_weights_array.data_start = AI_PTR(weights + 0);
  
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_mobilenet_128_0_25_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_MOBILENET_128_0_25_MODEL_NAME,
      .model_signature   = AI_MOBILENET_128_0_25_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 12648912,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_mobilenet_128_0_25_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_mobilenet_128_0_25_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_mobilenet_128_0_25_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_mobilenet_128_0_25_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= mobilenet_128_0_25_configure_weights(net_ctx, &params->params);
  ok &= mobilenet_128_0_25_configure_activations(net_ctx, &params->activations);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_mobilenet_128_0_25_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_mobilenet_128_0_25_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_MOBILENET_128_0_25_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

