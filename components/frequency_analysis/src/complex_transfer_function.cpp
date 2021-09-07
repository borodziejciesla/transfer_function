/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#include "complex_transfer_function.hpp"

#include <numeric>

#include "complex.hpp"

namespace tf_core
{
    ComplexTransferFunction::ComplexTransferFunction(const CoreTransferFunction & tf)
        : tf_{tf} {
    }

    std::tuple<float, float>  ComplexTransferFunction::operator()(const float w) const {
        const auto omega = Complex(0.0f, w);

        auto num = std::accumulate(tf_.GetNum().GetCoefficients().begin(), tf_.GetNum().GetCoefficients().end(), Complex(0.0f, 0.0f),
            [=](Complex sum, const float coefficient) {
                static int pow = 0;

                auto w_power = omega^pow;

                return (sum + w_power * coefficient);
            }
        );

        auto den = std::accumulate(tf_.GetDen().GetCoefficients().begin(), tf_.GetDen().GetCoefficients().end(), Complex(0.0f, 0.0f),
            [=](Complex sum, const float coefficient) {
                static int pow = 0;

                auto w_power = omega^pow;

                return (sum + w_power * coefficient);
            }
        );

        auto value = num / den;

        return std::make_tuple(value.Real(), value.Img());
    }
}   //  namespace tf_core
