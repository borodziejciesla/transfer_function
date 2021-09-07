/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#ifndef TRANSFER_FUNCTION_COMPONENTS_FREQUENCY_ANALYSIS_COMPLEX_TRANSFER_FUNCTION_HPP_
#define TRANSFER_FUNCTION_COMPONENTS_FREQUENCY_ANALYSIS_COMPLEX_TRANSFER_FUNCTION_HPP_

#include <tuple>

#include "core_transfer_function.hpp"

namespace tf_core
{
    class ComplexTransferFunction
    {
        public:
            explicit ComplexTransferFunction(const CoreTransferFunction & tf);
            ComplexTransferFunction(void) = delete;
            ~ComplexTransferFunction(void) = default;

            std::tuple<float, float> operator()(const float w) const;

        private:
            CoreTransferFunction tf_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_COMPONENTS_FREQUENCY_ANALYSIS_COMPLEX_TRANSFER_FUNCTION_HPP_
