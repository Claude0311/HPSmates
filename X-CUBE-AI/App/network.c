/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Mar 20 05:59:22 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "6679009de92858d6a63fc47fd33bb5f5"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.0.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Mar 20 05:59:22 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array dense_1_bias_array;   /* Array #0 */
AI_STATIC ai_array dense_1_weights_array;   /* Array #1 */
AI_STATIC ai_array lstm_2_bias_array;   /* Array #2 */
AI_STATIC ai_array lstm_2_peephole_array;   /* Array #3 */
AI_STATIC ai_array lstm_2_recurrent_array;   /* Array #4 */
AI_STATIC ai_array lstm_2_kernel_array;   /* Array #5 */
AI_STATIC ai_array lstm_1_bias_array;   /* Array #6 */
AI_STATIC ai_array lstm_1_peephole_array;   /* Array #7 */
AI_STATIC ai_array lstm_1_recurrent_array;   /* Array #8 */
AI_STATIC ai_array lstm_1_kernel_array;   /* Array #9 */
AI_STATIC ai_array input_0_output_array;   /* Array #10 */
AI_STATIC ai_array lstm_1_output_array;   /* Array #11 */
AI_STATIC ai_array lstm_2_output_array;   /* Array #12 */
AI_STATIC ai_array dense_1_output_array;   /* Array #13 */
AI_STATIC ai_array dense_1_nl_output_array;   /* Array #14 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor dense_1_bias;   /* Tensor #0 */
AI_STATIC ai_tensor dense_1_weights;   /* Tensor #1 */
AI_STATIC ai_tensor lstm_2_bias;   /* Tensor #2 */
AI_STATIC ai_tensor lstm_2_peephole;   /* Tensor #3 */
AI_STATIC ai_tensor lstm_2_recurrent;   /* Tensor #4 */
AI_STATIC ai_tensor lstm_2_kernel;   /* Tensor #5 */
AI_STATIC ai_tensor lstm_1_bias;   /* Tensor #6 */
AI_STATIC ai_tensor lstm_1_peephole;   /* Tensor #7 */
AI_STATIC ai_tensor lstm_1_recurrent;   /* Tensor #8 */
AI_STATIC ai_tensor lstm_1_kernel;   /* Tensor #9 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #10 */
AI_STATIC ai_tensor lstm_1_output;   /* Tensor #11 */
AI_STATIC ai_tensor lstm_2_output;   /* Tensor #12 */
AI_STATIC ai_tensor dense_1_output;   /* Tensor #13 */
AI_STATIC ai_tensor dense_1_nl_output;   /* Tensor #14 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain lstm_1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain lstm_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_1_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_1_nl_chain;   /* Chain #3 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_lstm lstm_1_layer; /* Layer #0 */
AI_STATIC ai_layer_lstm lstm_2_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_1_layer; /* Layer #2 */
AI_STATIC ai_layer_nl dense_1_nl_layer; /* Layer #3 */


/**  Array declarations section  **********************************************/
AI_ARRAY_OBJ_DECLARE(
    dense_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 6,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 8,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_2_peephole_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 6,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_2_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_2_kernel_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 80,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 40,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_1_peephole_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 30,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_1_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 400,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_1_kernel_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 40,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 20,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_1_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 200,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    lstm_2_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 2,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_1_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_1_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 3,
     AI_STATIC)




/**  Tensor declarations section  *********************************************/
AI_TENSOR_OBJ_DECLARE(
  dense_1_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_1_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_1_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 2, 3, 1, 1), AI_STRIDE_INIT(4, 4, 8, 24, 24),
  1, &dense_1_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_2_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &lstm_2_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_2_peephole, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &lstm_2_peephole_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_2_recurrent, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 2, 1, 1, 8), AI_STRIDE_INIT(4, 4, 8, 8, 8),
  1, &lstm_2_recurrent_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_2_kernel, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 10, 1, 1, 8), AI_STRIDE_INIT(4, 4, 40, 40, 40),
  1, &lstm_2_kernel_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_1_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &lstm_1_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_1_peephole, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 30, 1, 1), AI_STRIDE_INIT(4, 4, 4, 120, 120),
  1, &lstm_1_peephole_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_1_recurrent, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 10, 1, 1, 40), AI_STRIDE_INIT(4, 4, 40, 40, 40),
  1, &lstm_1_recurrent_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_1_kernel, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 1, 1, 40), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &lstm_1_kernel_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 1, 1, 20), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &input_0_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_1_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 10, 1, 20), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &lstm_1_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  lstm_2_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &lstm_2_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_1_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_1_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_1_nl_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_1_nl_output_array, NULL)


/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  lstm_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&lstm_1_output),
  AI_TENSOR_LIST_ENTRY(&lstm_1_kernel, &lstm_1_recurrent, &lstm_1_peephole, &lstm_1_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  lstm_1_layer, 0,
  LSTM_TYPE,
  lstm, forward_lstm,
  &AI_NET_OBJ_INSTANCE, &lstm_2_layer, AI_STATIC,
  .tensors = &lstm_1_chain, 
  .n_units = 10, 
  .activation_nl = ai_math_tanh, 
  .recurrent_nl = ai_math_sigmoid, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .out_nl = ai_math_tanh, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  lstm_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&lstm_1_output),
  AI_TENSOR_LIST_ENTRY(&lstm_2_output),
  AI_TENSOR_LIST_ENTRY(&lstm_2_kernel, &lstm_2_recurrent, &lstm_2_peephole, &lstm_2_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  lstm_2_layer, 2,
  LSTM_TYPE,
  lstm, forward_lstm,
  &AI_NET_OBJ_INSTANCE, &dense_1_layer, AI_STATIC,
  .tensors = &lstm_2_chain, 
  .n_units = 2, 
  .activation_nl = ai_math_tanh, 
  .recurrent_nl = ai_math_sigmoid, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .out_nl = ai_math_tanh, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&lstm_2_output),
  AI_TENSOR_LIST_ENTRY(&dense_1_output),
  AI_TENSOR_LIST_ENTRY(&dense_1_weights, &dense_1_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_layer, 4,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_1_nl_layer, AI_STATIC,
  .tensors = &dense_1_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_1_output),
  AI_TENSOR_LIST_ENTRY(&dense_1_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_nl_layer, 4,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &dense_1_nl_layer, AI_STATIC,
  .tensors = &dense_1_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 2516, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 808, 1,
                     NULL),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &dense_1_nl_output),
  &lstm_1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    lstm_1_output_array.data = AI_PTR(activations + 0);
    lstm_1_output_array.data_start = AI_PTR(activations + 0);
    lstm_2_output_array.data = AI_PTR(activations + 800);
    lstm_2_output_array.data_start = AI_PTR(activations + 800);
    dense_1_output_array.data = AI_PTR(activations + 0);
    dense_1_output_array.data_start = AI_PTR(activations + 0);
    dense_1_nl_output_array.data = AI_PTR(NULL);
    dense_1_nl_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_1_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_1_bias_array.data = AI_PTR(weights + 2504);
    dense_1_bias_array.data_start = AI_PTR(weights + 2504);
    dense_1_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_1_weights_array.data = AI_PTR(weights + 2480);
    dense_1_weights_array.data_start = AI_PTR(weights + 2480);
    lstm_2_bias_array.format |= AI_FMT_FLAG_CONST;
    lstm_2_bias_array.data = AI_PTR(weights + 2448);
    lstm_2_bias_array.data_start = AI_PTR(weights + 2448);
    lstm_2_peephole_array.format |= AI_FMT_FLAG_CONST;
    lstm_2_peephole_array.data = AI_PTR(weights + 2424);
    lstm_2_peephole_array.data_start = AI_PTR(weights + 2424);
    lstm_2_recurrent_array.format |= AI_FMT_FLAG_CONST;
    lstm_2_recurrent_array.data = AI_PTR(weights + 2360);
    lstm_2_recurrent_array.data_start = AI_PTR(weights + 2360);
    lstm_2_kernel_array.format |= AI_FMT_FLAG_CONST;
    lstm_2_kernel_array.data = AI_PTR(weights + 2040);
    lstm_2_kernel_array.data_start = AI_PTR(weights + 2040);
    lstm_1_bias_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_bias_array.data = AI_PTR(weights + 1880);
    lstm_1_bias_array.data_start = AI_PTR(weights + 1880);
    lstm_1_peephole_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_peephole_array.data = AI_PTR(weights + 1760);
    lstm_1_peephole_array.data_start = AI_PTR(weights + 1760);
    lstm_1_recurrent_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_recurrent_array.data = AI_PTR(weights + 160);
    lstm_1_recurrent_array.data_start = AI_PTR(weights + 160);
    lstm_1_kernel_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_kernel_array.data = AI_PTR(weights + 0);
    lstm_1_kernel_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
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
      
      .n_macc            = 11971,
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
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

