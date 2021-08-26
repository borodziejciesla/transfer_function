/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#ifndef TRANSFER_FUNCTION_COMPONENTS_C2D_SRC_POLYNOMIAL_FRACTION_HPP_
#define TRANSFER_FUNCTION_COMPONENTS_C2D_SRC_POLYNOMIAL_FRACTION_HPP_

#include "polynomial.hpp"

namespace tf_core
{
    class PolynomialFraction
    {
        public:
            PolynomialFraction(const Polynomial & num, const Polynomial & den);
            ~PolynomialFraction(void) = default;

            PolynomialFraction & operator+=(const PolynomialFraction & rhs);
            PolynomialFraction & operator-=(const PolynomialFraction & rhs);
            PolynomialFraction operator*(const float & rhs);

            PolynomialFraction Power(const size_t n);
            
            const Polynomial & GetNum(void) const;
            const Polynomial & GetDen(void) const;

        private:
            Polynomial num_;
            Polynomial den_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_COMPONENTS_C2D_SRC_POLYNOMIAL_FRACTION_HPP_
