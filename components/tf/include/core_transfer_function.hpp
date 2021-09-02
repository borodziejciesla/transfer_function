/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#ifndef TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_CORE_TRANSFER_FUNCTION_HPP_
#define TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_CORE_TRANSFER_FUNCTION_HPP_

#include "polynomial.hpp"
#include "polynomial_discretizer.hpp"

namespace tf_core
{
    class CoreTransferFunction
    {
        public:
            CoreTransferFunction(void) = delete;
            CoreTransferFunction(const Polynomial & num, const Polynomial & den);
            ~CoreTransferFunction(void) = default;

            CoreTransferFunction Series(const CoreTransferFunction & rhs) const;
            CoreTransferFunction Parallel(const CoreTransferFunction & rhs) const;
            CoreTransferFunction Feedback(const CoreTransferFunction & feedback_branch, bool positive = false) const;

            CoreTransferFunction operator+(const CoreTransferFunction & rhs) const;
            CoreTransferFunction operator*(const CoreTransferFunction & rhs) const;

            bool operator==(const CoreTransferFunction & rhs) const;
            bool operator!=(const CoreTransferFunction & rhs) const;

            const Polynomial & GetNum(void) const;
            const Polynomial & GetDen(void) const;
            
        private:
            Polynomial num_;
            Polynomial den_;            
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_CORE_TRANSFER_FUNCTION_HPP_
