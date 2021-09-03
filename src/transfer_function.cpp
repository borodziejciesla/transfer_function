#include "transfer_function.hpp"

#include <tuple>

#include "core_transfer_function.hpp"
#include "polynomial.hpp"

namespace tf_core
{
    TransferFunction::TransferFunction(const std::vector<float> & num, const std::vector<float> & den)
        : num_{std::make_unique<Polynomial>(num)}
        , den_{std::make_unique<Polynomial>(den)}
        , tf_{std::make_unique<CoreTransferFunction>(*num_, *den_)} {
        std::ignore = num;
        std::ignore = den;
    }

    TransferFunction::~TransferFunction(void) {}

}   //  namespace tf_core
