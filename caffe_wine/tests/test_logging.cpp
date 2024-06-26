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


//#include "caffe/logging.hpp"
//#include <gtest/gtest.h>
/*
TEST(LoggingTest, InfoLog) {
testing::internal::CaptureStderr();
LOG(INFO) << "Info message";
std::string output = testing::internal::GetCapturedStderr();
EXPECT_NE(output.find("Info message"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/

#include "caffe/logging.h"
#include "simple_test.hpp"
#include <sstream>  // Include the necessary header

TEST(LoggingTest, InfoLog) {
    std::ostringstream oss;
    std::streambuf* old_cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    LogMessage(caffe::LogLevel::INFO,"Info message") ; //<< "Info message";

    std::cerr.rdbuf(old_cerr_buf);

    EXPECT_NE(oss.str().find("Info message"), std::string::npos);

    return 0;
}

//int main() {
//    RUN_TEST(LoggingTest, InfoLog);
//    return 0;
//}