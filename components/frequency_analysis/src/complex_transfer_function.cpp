/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#include "complex_transfer_function.hpp"

#include <algorithm>
#include <numeric>

namespace tf_core
{
    ComplexTransferFunction::ComplexTransferFunction(const CoreTransferFunction & tf)
        : tf_{tf} {
    }

    Characteristic ComplexTransferFunction::CalculateBode(const Frequencies & omega) const {
        auto complex_characteristic = CalculateCharacteristics(omega);

        Characteristic bode_characteristic(omega.size());
        std::transform(complex_characteristic.begin(), complex_characteristic.end(), bode_characteristic.begin(),
            [](const Complex v) {
                return std::pair<float, float>(v.Abs(), v.Phase());
            }
        );
    }

    Characteristic ComplexTransferFunction::CalculateNyquist(const Frequencies & omega) const {
        auto complex_characteristic = CalculateCharacteristics(omega);

        Characteristic bode_characteristic(omega.size());
        std::transform(complex_characteristic.begin(), complex_characteristic.end(), bode_characteristic.begin(),
            [](const Complex v) {
                return std::pair<float, float>(v.Real(), v.Img());
            }
        );
    }

    ComplexCharacteristic ComplexTransferFunction::CalculateCharacteristics(const Frequencies & omega) const {
        ComplexCharacteristic characteristic(omega.size());

        std::transform(omega.begin(), omega.end(), characteristic.begin(),
            [this](const float w) {
                return CalculateValue(w);
            }
        );

        return characteristic;
    }

    Complex  ComplexTransferFunction::CalculateValue(const float w) const {
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

        return (num / den);
    }
}   //  namespace tf_core
