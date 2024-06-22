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

#ifndef CAFFE_WINE_LOGGING_H
#define CAFFE_WINE_LOGGING_H

#include <iostream>
#include <stdexcept>  // For std::runtime_error
#include <sstream>    // For std::ostringstream

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace caffe {

// Logging levels
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

// Log function to output messages based on log level
    inline void LogMessage(LogLevel level, const std::string& message) {
        switch (level) {
            case LogLevel::INFO:
                std::cout << "INFO: " << message << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "WARNING: " << message << std::endl;
                break;
            case LogLevel::ERROR:
                std::cerr << "ERROR: " << message << std::endl;
                break;
            case LogLevel::FATAL:
                std::cerr << "FATAL: " << message << std::endl;
                std::terminate();  // Terminate program on fatal error
                break;
        }
    }

// Assertion macro
#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            std::ostringstream oss; \
            oss << "Check failed: " #condition " "; \
            caffe::LogMessage(caffe::LogLevel::FATAL, oss.str()); \
        } \
    } while (0)

// Check macros for specific conditions
#define CHECK_LT(val1, val2) CHECK((val1) < (val2))
#define CHECK_LE(val1, val2) CHECK((val1) <= (val2))
#define CHECK_GT(val1, val2) CHECK((val1) > (val2))
#define CHECK_GE(val1, val2) CHECK((val1) >= (val2))
#define CHECK_EQ(val1, val2) CHECK((val1) == (val2))
#define CHECK_NE(val1, val2) CHECK((val1) != (val2))

// Log macros for different log levels
#define LOG_INFO(message) caffe::LogMessage(caffe::LogLevel::INFO, message)
#define LOG_WARNING(message) caffe::LogMessage(caffe::LogLevel::WARNING, message)
#define LOG_ERROR(message) caffe::LogMessage(caffe::LogLevel::ERROR, message)
#define LOG_FATAL(message) caffe::LogMessage(caffe::LogLevel::FATAL, message)

// Not implemented macro
#define NOT_IMPLEMENTED LOG_FATAL("Not implemented yet.")

}  // namespace caffe


#endif //CAFFE_WINE_LOGGING_H
