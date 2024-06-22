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
#ifndef CAFFE_WINE_BASE_HPP
#define CAFFE_WINE_BASE_HPP


#include <vector>
#include <iostream>

#include <string>
#include <vector>
#include <memory>

#include <caffe/logging.h>

#ifdef _MSC_VER
#ifdef CAFFE_EXPORTS
#define CAFFE_API __declspec(dllexport)
#else
#define CAFFE_API __declspec(dllimport)
#endif
#else
#define CAFFE_API
#endif

#ifdef _MSC_VER
#pragma warning(disable:4251)
#endif

// Convert macro to string
#define STRINGIFY(m) #m
#define AS_STRING(m) STRINGIFY(m)

// Disable the copy and assignment operator for a class.
#define DISABLE_COPY_AND_ASSIGN(classname)            \
private:                                              \
  classname(const classname&) = delete;               \
  classname(classname&&) = delete;                    \
  classname& operator=(const classname&) = delete;    \
  classname& operator=(classname&&) = delete

// A simple macro to mark codes that are not implemented, so that when the code
// is executed we will see a fatal log.
//#define NOT_IMPLEMENTED LOG(FATAL) << "Not Implemented Yet"
#define NO_GPU LOG(FATAL) << "Cannot use GPU in CPU-only Caffe: check mode."

namespace caffe {

// Common functions and classes from std that caffe often uses.
    using std::vector;
    using std::string;
    using std::shared_ptr;

    typedef float real_t;

    enum DeviceMode {
        CPU, GPU
    };

/*!
 * \brief gpu available
 * \return true if gpu available
 */
    CAFFE_API bool GPUAvailable();
/*!
 * \brief set caffe mode
 * \param mode GPU or CPU
 * \param device GPU device id, -1 for CPU
 */
    CAFFE_API void SetMode(DeviceMode mode, int device);

//// ThreadLocal Memory Pool API

    struct MemPoolState {
        int gpu_mem;  // gpu memory, calculate on all device memory used by this thread
        int cpu_mem;  // cpu memory
        int unused_gpu_mem;  // not used gpu memory
        int unused_cpu_mem;  // not used cpu memory
    };
/*! \brief get memory usage in current thread */
    CAFFE_API MemPoolState MemPoolGetState();
/*! \brief clear unused memory pool in current thread */
    CAFFE_API void MemPoolClear();

}  // namespace caffe

#endif //CAFFE_WINE_BASE_HPP
