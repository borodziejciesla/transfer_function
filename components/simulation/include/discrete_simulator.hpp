/* Copyright (C) 2021 Maciej Rozewicz - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 *
 * You should have received a copy of the XYZ license with
 * this file. If not, please write to: , or visit :
 */

#ifndef TRANSFER_FUNCTION_COMPONENTS_SIMULATION_DISCRETE_SIMULATION_HPP_
#define TRANSFER_FUNCTION_COMPONENTS_SIMULATION_DISCRETE_SIMULATION_HPP_

#include <vector>

#include "core_transfer_function.hpp"

namespace tf_core
{
    using Signal = std::vector<float>;

    class DiscreteSimulator
    {
        public:
            DiscreteSimulator(void) = delete;
            DiscreteSimulator(const DiscreteSimulator & obbj) = delete;
            DiscreteSimulator(const DiscreteSimulator && obj) = delete;
            ~DiscreteSimulator(void) = delete;

            static Signal Simulate(const CoreTransferFunction & tf, const Signal & input_signal);        
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_COMPONENTS_SIMULATION_DISCRETE_SIMULATION_HPP_
