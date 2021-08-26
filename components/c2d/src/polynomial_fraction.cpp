#include "polynomial_fraction.hpp"

namespace tf_core
{
    PolynomialFraction::PolynomialFraction(const Polynomial & num, const Polynomial & den)
        : num_{num}
        , den_{den} {
    }

    PolynomialFraction & PolynomialFraction::operator+=(const PolynomialFraction & rhs) {
        auto new_den = this->den_ * rhs.den_;
        auto new_num = this->num_ * rhs.den_ + this->den_ * rhs.num_;

        this->num_ = new_num;
        this->den_ = new_den;

        return (*this);
    }

    PolynomialFraction & PolynomialFraction::operator-=(const PolynomialFraction & rhs) {
        auto new_den = this->den_ * rhs.den_;
        auto new_num = this->num_ * rhs.den_ - this->den_ * rhs.num_;

        this->num_ = new_num;
        this->den_ = new_den;

        return (*this);
    }

    PolynomialFraction PolynomialFraction::operator*(const float & rhs) {
        return PolynomialFraction(num_ * rhs, den_);
    }

    PolynomialFraction PolynomialFraction::Power(const size_t n) {
        return PolynomialFraction(num_.Power(n), den_.Power(n));
    }

    const Polynomial & PolynomialFraction::GetNum(void) const {
        return num_;
    }

    const Polynomial & PolynomialFraction::GetDen(void) const {
        return den_;
    }
}   // namespace tf_core
