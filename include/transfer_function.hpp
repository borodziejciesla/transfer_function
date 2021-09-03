#ifndef TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_
#define TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_

#include <memory>
#include <vector>

namespace tf_core
{
    class CoreTransferFunction;
    class Polynomial;

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

        private:
            explicit TransferFunction(const CoreTransferFunction & core_tf);

            std::unique_ptr<Polynomial> num_;
            std::unique_ptr<Polynomial> den_;
            std::unique_ptr<CoreTransferFunction> tf_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_
