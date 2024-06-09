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

#ifndef CAFFE_WINE_LOGGING_HPP
#define CAFFE_WINE_LOGGING_HPP
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace caffe {

// Logging levels
    enum LogLevel {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

// Log message class to handle different log levels
    class LogMessage {
    public:
        LogMessage(LogLevel level) : level_(level) {}
        ~LogMessage() {
            if (level_ == FATAL) {
                std::cerr << stream_.str() << std::endl;
                throw std::runtime_error(stream_.str());
            } else {
                std::cerr << stream_.str() << std::endl;
            }
        }

        std::ostringstream& stream() { return stream_; }

    private:
        LogLevel level_;
        std::ostringstream stream_;
    };

// Log message macro
#define LOG(level) ::caffe::LogMessage(::caffe::level).stream()

}  // namespace caffe
#endif //CAFFE_WINE_LOGGING_HPP
