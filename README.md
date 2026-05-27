# Edge Computing and TinyML: Session 1-5 Final Project

**Authors:** Ikenna Ihetu (2202278) & Chibueze Ihetu  
**Course:** IT00CS34 Edge Computing for ML  

This repository contains the source code, models, and notebooks for two TinyML projects deployed on the Arduino Nano 33 BLE Sense.

## Project 1: Audio Keyword Spotting
- **Goal:** Recognize the keywords "Kathmandu" and "Islamabad" in the phrase "What is the weather in..." using an Artificial Neural Network.
- **Tools:** Edge Impulse, Arduino CLI.
- **Status:** Trained using MFCC feature extraction and deployed as an Arduino library.

## Project 2: Rock-Paper-Scissors Image Classification
- **Goal:** Perform on-device image classification using the OV7670 camera module.
- **Workflow:**
    1. **Training:** Trained a CNN on the RPS dataset in Google Colab.
    2. **Optimization:** Applied Polynomial Decay Pruning and Full Integer Quantization (uint8).
    3. **Deployment:** Converted the model to a C++ header file and deployed using TensorFlow Lite Micro.
- **Files included:**
    - `EdgeML26.ipynb`: The full training and optimization pipeline.
    - `model_quant.tflite`: The final quantized model file.
    - `model.h`: The C++ header file containing the model array for Arduino.
    - `image_data.h`: Static test image for model verification.

## Hardware Used
- Arduino Nano 33 BLE Sense
- OV7670 Camera Module
- Breadboard and Jumper Wires

## Software & Libraries
- TensorFlow Lite Micro
- TensorFlow Model Optimization Toolkit
- Arduino IDE
- Edge Impulse CLI
