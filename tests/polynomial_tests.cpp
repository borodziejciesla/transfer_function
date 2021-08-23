#include "gtest/gtest.h"

#include <memory>

#include "polynomial.hpp"

class PolynomialTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}
};

TEST_F(PolynomialTests, TestDefaultConstructor) {
    EXPECT_NO_THROW(auto tf = std::make_unique<tf_core::Polynomial>());
}

TEST_F(PolynomialTests, TestCopyingConstructor) {
    tf_core::Polynomial p = tf_core::Polynomial();
    EXPECT_NO_THROW(auto tf = std::make_unique<tf_core::Polynomial>(p));
}

TEST_F(PolynomialTests, TestExplicitConstructorConstructor) {
    std::vector<float> coefficients = {1.0f, 2.0f, 3.0f};
    EXPECT_NO_THROW(auto tf = std::make_unique<tf_core::Polynomial>(coefficients));
}

TEST_F(PolynomialTests, TestGetCoefficients) {
    std::vector<float> coefficients = {1.0f, 2.0f, 3.0f};
    auto tf = tf_core::Polynomial(coefficients);

    EXPECT_EQ(coefficients, tf.GetCoefficients());
}