# Edge Computing and TinyML: Session 1-5 Final Project

**Authors:** 
- Ikenna Ihetu (2202278)
- Chibueze Ihetu (2102787)

**Course:** IT00CS34 Edge Computing for ML  

This repository contains the source code, models, and notebooks for two TinyML projects deployed on the Arduino Nano 33 BLE Sense.

## Project 1: Audio Keyword Spotting
- **Goal:** Recognize the keywords "Kathmandu" and "Islamabad" in the phrase "What is the weather in..." using an Artificial Neural Network.
- **Tools:** Edge Impulse, Arduino CLI.
- **Implementation:** Trained using MFCC feature extraction and deployed as an Arduino library to run continuously on the board's built-in microphone.

## Project 2: Rock-Paper-Scissors Image Classification
- **Goal:** Perform on-device image classification using the OV7670 camera module.
- **Workflow:**
    1. **Training:** Trained a CNN on the RPS dataset in Google Colab.
    2. **Optimization:** Applied Polynomial Decay Pruning and Full Integer Quantization (uint8).
    3. **Deployment:** Converted the model to a C++ header file and deployed using TensorFlow Lite Micro.

### Performance Metrics (Project 2)
| Model Version | Accuracy (Python) | Accuracy (Arduino) | Latency | Model Size |
| :--- | :--- | :--- | :--- | :--- |
| **Full Precision** | 87.10% | N/A (Too Large) | ~5ms (PC) | 69.86 KB |
| **Quantized (uint8) & Pruned** | 86.02% | 86.02% | 58 ms | 17.06 KB |

---

## Repository Structure & Key Files

*   `EdgeML26.ipynb`: The Google Colab notebook containing the model training, pruning, and quantization pipeline.
*   `sketch.ino`: Main Arduino code configured with the custom `tensor_arena` (60 KB) and `MicroMutableOpResolver`.
*   `model_quant.tflite`: The final quantized model file.
*   `model.h`: The generated C++ header file containing the model array.
*   `image_data.h`: Pre-made static test image used to verify on-device predictions.

## Hardware Used
- Arduino Nano 33 BLE Sense
- OV7670 Camera Module
- Breadboard and Jumper Wires

## Software & Libraries
- TensorFlow Lite Micro
- TensorFlow Model Optimization Toolkit
- Arduino IDE (and `Arduino_OV767X` library)
- Edge Impulse CLI
