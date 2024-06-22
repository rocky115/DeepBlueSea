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

#include "caffe/blob.h"
#include <caffe/logging.h>

namespace caffe {

    Blob::Blob(const int num, const int channels, const int height, const int width)
            : data_(), count_(0), capacity_(0), name_(""), own_data_(false) {
        Reshape(num, channels, height, width);
    }

    Blob::Blob(const std::vector<int>& shape)
            : data_(), count_(0), capacity_(0), name_(""), own_data_(false) {
        Reshape(shape);
    }

    void Blob::Reshape(const int num, const int channels, const int height, const int width) {
        shape_ = { num, channels, height, width };
        count_ = num * channels * height * width;
    }

    void Blob::Reshape(const std::vector<int>& shape) {
        shape_ = shape;
        count_ = 1;
        for (int s : shape_) {
            count_ *= s;
        }
    }

    void Blob::Reshape(const BlobShape& shape) {
        // Implement Blob::Reshape with BlobShape if necessary
        NOT_IMPLEMENTED;
    }

    void Blob::ReshapeLike(const Blob& other) {
        Reshape(other.shape());
    }



    void Blob::CopyFrom(const Blob& source, bool reshape) {
        NOT_IMPLEMENTED;
    }


    const int* Blob::gpu_shape() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const real_t* Blob::cpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const real_t* Blob::gpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    real_t* Blob::mutable_cpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    real_t* Blob::mutable_gpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    void Blob::FromProto(const BlobProto& proto, bool reshape) {
        NOT_IMPLEMENTED;
    }

    void Blob::ToProto(BlobProto* proto) const {
        NOT_IMPLEMENTED;
    }

    void Blob::ShareData(const Blob& other) {
        NOT_IMPLEMENTED;
    }

    bool Blob::ShapeEquals(const BlobProto& other) {
        NOT_IMPLEMENTED;
        return false;
    }

    void Blob::ResetMemory() {
        NOT_IMPLEMENTED;
    }



    const int* BlobInt::cpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const int* BlobInt::gpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    int* BlobInt::mutable_cpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    int* BlobInt::mutable_gpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

}  // namespace caffe



/**
namespace caffe {

    Blob::Blob(const int num, const int channels, const int height, const int width)
            : data_(), count_(0), capacity_(0), name_(""), own_data_(false) {
        Reshape(num, channels, height, width);
    }

    Blob::Blob(const std::vector<int>& shape)
            : data_(), count_(0), capacity_(0), name_(""), own_data_(false) {
        Reshape(shape);
    }

    void Blob::Reshape(const int num, const int channels, const int height, const int width) {
        shape_ = { num, channels, height, width };
        count_ = num * channels * height * width;
    }

    void Blob::Reshape(const std::vector<int>& shape) {
        shape_ = shape;
        count_ = 1;
        for (int s : shape_) {
            count_ *= s;
        }
    }

    void Blob::Reshape(const BlobShape& shape) {
        // Implement Blob::Reshape with BlobShape if necessary
        NOT_IMPLEMENTED;
    }

    void Blob::ReshapeLike(const Blob& other) {
        Reshape(other.shape());
    }

    std::string Blob::shape_string() const {
        std::ostringstream stream;
        for (int i = 0; i < shape_.size(); ++i) {
            stream << shape_[i] << " ";
        }
        stream << "(" << count_ << ")";
        return stream.str();
    }

    const std::vector<int>& Blob::shape() const {
        return shape_;
    }

    int Blob::shape(int index) const {
        return shape_[CanonicalAxisIndex(index)];
    }

    int Blob::num_axes() const {
        return static_cast<int>(shape_.size());
    }

    int Blob::count() const {
        return count_;
    }

    int Blob::capacity() const {
        return capacity_;
    }

    int Blob::count(int start_axis, int end_axis) const {
        if (start_axis > end_axis || start_axis < 0 || end_axis < 0 || start_axis > num_axes() || end_axis > num_axes()) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Invalid range specified in Blob::count()");
        }

        int count = 1;
        for (int i = start_axis; i < end_axis; ++i) {
            count *= shape(i);
        }
        return count;
    }

    int Blob::count(int start_axis) const {
        return count(start_axis, num_axes());
    }

    int Blob::CanonicalAxisIndex(int axis_index) const {
        if (axis_index < -num_axes() || axis_index >= num_axes()) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Invalid axis index in Blob::CanonicalAxisIndex()");
        }

        if (axis_index < 0) {
            return axis_index + num_axes();
        }
        return axis_index;
    }

    int Blob::num() const {
        return LegacyShape(0);
    }

    int Blob::channels() const {
        return LegacyShape(1);
    }

    int Blob::height() const {
        return LegacyShape(2);
    }

    int Blob::width() const {
        return LegacyShape(3);
    }

    int Blob::LegacyShape(int index) const {
        if (num_axes() > 4) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Legacy accessors not supported for Blobs with more than 4 axes");
        }

        if (index < 0 || index >= 4) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Invalid index in Blob::LegacyShape()");
        }

        return shape(index);
    }

    int Blob::offset(const int n, const int c, const int h, const int w) const {
        if (n < 0 || n >= shape(0) ||
            c < 0 || c >= shape(1) ||
            h < 0 || h >= shape(2) ||
            w < 0 || w >= shape(3)) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Index out of range in Blob::offset()");
        }

        return ((n * channels() + c) * height() + h) * width() + w;
    }

    int Blob::offset(const std::vector<int>& indices) const {
        if (indices.size() > num_axes()) {
            // Handle error condition gracefully (e.g., throw exception, log error, etc.)
            // For example:
            throw std::runtime_error("Too many indices specified in Blob::offset()");
        }

        int offset = 0;
        for (int i = 0; i < num_axes(); ++i) {
            if (i < indices.size()) {
                if (indices[i] < 0 || indices[i] >= shape(i)) {
                    // Handle error condition gracefully (e.g., throw exception, log error, etc.)
                    // For example:
                    throw std::runtime_error("Index out of range in Blob::offset()");
                }
                offset += indices[i];
            } else {
                offset *= shape(i);
            }
        }
        return offset;
    }

    void Blob::CopyFrom(const Blob& source, bool reshape) {
        NOT_IMPLEMENTED;
    }

    real_t Blob::data_at(const int n, const int c, const int h, const int w) const {
        return cpu_data()[offset(n, c, h, w)];
    }

    real_t Blob::data_at(const std::vector<int>& index) const {
        return cpu_data()[offset(index)];
    }

    const int* Blob::gpu_shape() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const real_t* Blob::cpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const real_t* Blob::gpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    real_t* Blob::mutable_cpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    real_t* Blob::mutable_gpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    void Blob::FromProto(const BlobProto& proto, bool reshape) {
        NOT_IMPLEMENTED;
    }

    void Blob::ToProto(BlobProto* proto) const {
        NOT_IMPLEMENTED;
    }

    void Blob::ShareData(const Blob& other) {
        NOT_IMPLEMENTED;
    }

    bool Blob::ShapeEquals(const BlobProto& other) {
        NOT_IMPLEMENTED;
        return false;
    }

    void Blob::ResetMemory() {
        NOT_IMPLEMENTED;
    }

    int BlobInt::data_at(const int n, const int c, const int h, const int w) const {
        return cpu_data()[offset(n, c, h, w)];
    }

    int BlobInt::data_at(const std::vector<int>& index) const {
        return cpu_data()[offset(index)];
    }

    const int* BlobInt::cpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    const int* BlobInt::gpu_data() const {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    int* BlobInt::mutable_cpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

    int* BlobInt::mutable_gpu_data() {
        NOT_IMPLEMENTED;
        return nullptr;
    }

}  // namespace caffe

**/

