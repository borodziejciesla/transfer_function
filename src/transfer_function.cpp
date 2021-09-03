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

    TransferFunction::TransferFunction(const CoreTransferFunction & core_tf)
        : num_{std::make_unique<Polynomial>(core_tf.GetNum())}
        , den_{std::make_unique<Polynomial>(core_tf.GetDen())}
        , tf_{std::make_unique<CoreTransferFunction>(core_tf.GetNum(), core_tf.GetDen())}  { 
    }

    TransferFunction::~TransferFunction(void) = default;

    TransferFunction TransferFunction::Series(const TransferFunction & rhs) const {
        return TransferFunction((*tf_) * (*rhs.tf_));
    }

    TransferFunction TransferFunction::Parallel(const TransferFunction & rhs) const {
        return TransferFunction((*tf_) + (*rhs.tf_));
    }

    TransferFunction TransferFunction::Feedback(const TransferFunction & feedback_branch, bool positive) const {
        return TransferFunction(tf_->Feedback(*feedback_branch.tf_, positive));
    }

    TransferFunction TransferFunction::operator+(const TransferFunction & rhs) const {
        return TransferFunction((*tf_) + (*rhs.tf_));
    }

    TransferFunction TransferFunction::operator*(const TransferFunction & rhs) const {
        return TransferFunction((*tf_) * (*rhs.tf_));
    }

    bool TransferFunction::operator==(const TransferFunction & rhs) const {
        return (*tf_) == (*rhs.tf_);
    }

    bool TransferFunction::operator!=(const TransferFunction & rhs) const {
        return (*tf_) != (*rhs.tf_);
    }

    const TransferFunction::CoefficientsVector & TransferFunction::GetNum(void) const {
        return num_->GetCoefficients();
    }

    const TransferFunction::CoefficientsVector & TransferFunction::GetDen(void) const {
        return den_->GetCoefficients();
    }

}   //  namespace tf_core
