/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <string>

#include "matplotlibcpp.h"

#include "transfer_function.hpp"

namespace plt = matplotlibcpp;

int main(void) {
    tf_core::TransferFunction::CoefficientsVector num = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den = {1.0f, 0.1f, 0.1f};
    auto tf = tf_core::TransferFunction(num, den);

    auto response_length = 10.0f;
    auto impulse_response = tf.Impulse(response_length);

    std::vector<float> time(impulse_response.size());
    std::iota(time.begin(), time.end(), 0.0f);

    plt::figure();
    plt::plot(time, impulse_response, "b", {{"label", "EKF"}});
    plt::title("Impulse Response");
    plt::grid();
    plt::legend();
    plt::xlabel("Time [s]");
    plt::ylabel("y [s]");
    plt::show();

    return EXIT_SUCCESS;
}
