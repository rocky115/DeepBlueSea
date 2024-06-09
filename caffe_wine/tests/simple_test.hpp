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

#ifndef CAFFE_WINE_SIMPLE_TEST_HPP
#define CAFFE_WINE_SIMPLE_TEST_HPP

#include <iostream>
#include <string>

#define EXPECT_EQ(val1, val2) \
    if ((val1) != (val2)) { \
        std::cerr << __FILE__ << ":" << __LINE__ << ": " \
                  << "EXPECT_EQ failed: " << #val1 << " == " << #val2 \
                  << " (" << (val1) << " != " << (val2) << ")" << std::endl; \
        return 1; \
    }

#define EXPECT_NE(val1, val2) \
    if ((val1) == (val2)) { \
        std::cerr << __FILE__ << ":" << __LINE__ << ": " \
                  << "EXPECT_NE failed: " << #val1 << " != " << #val2 \
                  << " (" << (val1) << " == " << (val2) << ")" << std::endl; \
        return 1; \
    }

#define TEST(TestSuiteName, TestName) \
    int TestSuiteName##_##TestName()

#define RUN_TEST(TestSuiteName, TestName) \
    if (TestSuiteName##_##TestName() != 0) { \
        std::cerr << #TestSuiteName "." #TestName << " failed." << std::endl; \
        return 1; \
    } else { \
        std::cout << #TestSuiteName "." #TestName << " passed." << std::endl; \
    }

#endif //CAFFE_WINE_SIMPLE_TEST_HPP
