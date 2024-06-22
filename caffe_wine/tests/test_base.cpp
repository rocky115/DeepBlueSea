/*
 * Copyright (c) 2018 Radhamadhab Dalai
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "caffe/base.h"
#include <iostream>

int main() {
    // Test GPUAvailable
    if (caffe::GPUAvailable()) {
        std::cout << "GPU is available!" << std::endl;
    } else {
        std::cout << "GPU is not available." << std::endl;
    }

    // Test SetMode
    caffe::SetMode(caffe::GPU, 0);  // Setting GPU mode with device 0

    // Test MemPoolGetState
    caffe::MemPoolState state = caffe::MemPoolGetState();
    std::cout << "GPU Memory Used: " << state.gpu_mem << std::endl;
    std::cout << "CPU Memory Used: " << state.cpu_mem << std::endl;
    std::cout << "Unused GPU Memory: " << state.unused_gpu_mem << std::endl;
    std::cout << "Unused CPU Memory: " << state.unused_cpu_mem << std::endl;

    // Test MemPoolClear
    caffe::MemPoolClear();

    return 0;
}