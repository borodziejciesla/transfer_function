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
            TransferFunction(const std::vector<float> & num, const std::vector<float> & den);
            TransferFunction(void) = delete;
            ~TransferFunction(void);

        private:
            std::unique_ptr<Polynomial> num_;
            std::unique_ptr<Polynomial> den_;
            std::unique_ptr<CoreTransferFunction> tf_;
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_INCLUDE_TRANSFER_FUNCTION_HPP_
