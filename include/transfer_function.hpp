#ifndef TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_
#define TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_

#include <memory>
#include <vector>
#include <string>

#include "discretization_method.hpp"

namespace tf_core
{
    class CoreTransferFunction;
    class Polynomial;

    using Signal = std::vector<float>;

    class TransferFunction
    {
        public:
            using CoefficientsVector = std::vector<float>;

            TransferFunction(const CoefficientsVector & num, const CoefficientsVector & den);
            TransferFunction(void) = delete;
            ~TransferFunction(void);

            TransferFunction Series(const TransferFunction & rhs) const;
            TransferFunction Parallel(const TransferFunction & rhs) const;
            TransferFunction Feedback(const TransferFunction & feedback_branch, bool positive = false) const;

            TransferFunction operator+(const TransferFunction & rhs) const;
            TransferFunction operator*(const TransferFunction & rhs) const;

            bool operator==(const TransferFunction & rhs) const;
            bool operator!=(const TransferFunction & rhs) const;

            const CoefficientsVector & GetNum(void) const;
            const CoefficientsVector & GetDen(void) const;

            TransferFunction Discretize(const float discretization_time,
                const DiscretizationMethod discretization_method = DiscretizationMethod::Tustin) const;
            
            Signal SimulateDiscrete(const Signal & input_signal, const float sampling_time) const;
            Signal Step(float simulation_time) const;
            Signal Impulse(float simulation_time) const;

            std::string ToString(void) const;

        private:
            explicit TransferFunction(const CoreTransferFunction & core_tf);

            std::unique_ptr<Polynomial> num_;
            std::unique_ptr<Polynomial> den_;
            std::unique_ptr<CoreTransferFunction> tf_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_
