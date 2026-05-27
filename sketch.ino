#include <TensorFlowLite.h>
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "model.h"
#include "image_data.h"

// Define memory arena size - based on your model size
const int kTensorArenaSize = 60 * 1024;
uint8_t tensor_arena[kTensorArenaSize];

void setup() {
  Serial.begin(115200);
  
  // 1. Load the model
  const tflite::Model* tflite_model = tflite::GetModel(model);

  // 2. Set up the Op Resolver (adding only what the model needs saves space)
  static tflite::MicroMutableOpResolver<5> resolver;
  resolver.AddConv2D();
  resolver.AddMaxPool2D();
  resolver.AddReshape();
  resolver.AddFullyConnected();
  resolver.AddSoftmax();

  // 3. Build the interpreter
  static tflite::MicroInterpreter static_interpreter(
      tflite_model, resolver, tensor_arena, kTensorArenaSize);
  
  static_interpreter.AllocateTensors();
  TfLiteTensor* input = static_interpreter.input(0);

  // 4. Load the static image from image_data.h into the model input
  for (int i = 0; i < input->bytes; ++i) {
    input->data.uint8[i] = image_data[i];
  }

  // 5. Run Inference
  static_interpreter.Invoke();

  // 6. Read results
  TfLiteTensor* output = static_interpreter.output(0);
  Serial.print("Rock: "); Serial.println(output->data.uint8[0]);
  Serial.print("Paper: "); Serial.println(output->data.uint8[1]);
  Serial.print("Scissors: "); Serial.println(output->data.uint8[2]);
}

void loop() {}