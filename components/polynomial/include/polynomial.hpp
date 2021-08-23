/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#ifndef TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_INCLUDE_POLYNOMIAL_HPP_
#define TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_INCLUDE_POLYNOMIAL_HPP_

#include <vector>

namespace tf_core
{
    class Polynomial
    {
        public:
            using Coefficients = std::vector<float>;

            Polynomial(void);
            Polynomial(const Polynomial & polynomial) = default;
            Polynomial(Polynomial && polynomial) = default;
            ~Polynomial(void) = default;
            Polynomial & operator=(const Polynomial & polynomial) = delete;
            Polynomial & operator=(Polynomial && polynomial) = delete;

            explicit Polynomial(const Coefficients & coefficients);

            Polynomial operator+(const Polynomial & rhs) const;
            Polynomial & operator+=(const Polynomial & rhs);
            Polynomial operator-(const Polynomial & rhs) const;
            Polynomial & operator-=(const Polynomial & rhs);
            Polynomial operator*(const Polynomial & rhs) const;
            Polynomial & operator*=(const Polynomial & rhs);
            Polynomial operator*(const float & rhs) const;
            Polynomial & operator*=(const float & rhs);
            Polynomial operator/(const float & rhs) const;
            Polynomial & operator/=(const float & rhs);

            friend Polynomial operator*=(const float lhs, const Polynomial & rhs);

            const Coefficients & GetCoefficients(void) const;
            size_t GetPolynomialOrder(void) const;

        private:
            Coefficients coefficients_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_COMPONENTS_POLYNOMIAL_INCLUDE_POLYNOMIAL_HPP_
