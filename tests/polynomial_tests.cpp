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

TEST_F(PolynomialTests, TestOperatorPlusEqualSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    auto sum = a + b;

    std::vector<float> expected_result{5.0f, 7.0f, 9.0f};
    EXPECT_EQ(sum.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorPlusDifferentSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f, 4.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    auto sum = a + b;

    std::vector<float> expected_result{5.0f, 7.0f, 9.0f, 4.0f};
    EXPECT_EQ(sum.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorPlusEqualEqualSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    a += b;

    std::vector<float> expected_result{5.0f, 7.0f, 9.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorPlusEqualDifferentSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f, 4.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    a += b;

    std::vector<float> expected_result{5.0f, 7.0f, 9.0f, 4.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMinusEqualSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    auto sum = a - b;

    std::vector<float> expected_result{-3.0f, -3.0f, -3.0f};
    EXPECT_EQ(sum.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMinusDifferentSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f, 4.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    auto sum = a - b;

    std::vector<float> expected_result{-3.0f, -3.0f, -3.0f, 4.0f};
    EXPECT_EQ(sum.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMinusEqualEqualSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    a -= b;

    std::vector<float> expected_result{-3.0f, -3.0f, -3.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMinusEqualDifferentSize) {
    tf_core::Polynomial a({1.0f, 2.0f, 3.0f, 4.0f});
    tf_core::Polynomial b({4.0f, 5.0f, 6.0f});

    a -= b;

    std::vector<float> expected_result{-3.0f, -3.0f, -3.0f, 4.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMultiplyPolynomials) {
    tf_core::Polynomial a({1.0f, 2.0f});
    tf_core::Polynomial b({4.0f, 5.0f});

    auto mult = a * b;

    std::vector<float> expected_result{4.0f, 13.0f, 10.0f};
    EXPECT_EQ(mult.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorMultiplyEqualPolynomials) {
    tf_core::Polynomial a({1.0f, 2.0f});
    tf_core::Polynomial b({4.0f, 5.0f});

    a *= b;

    std::vector<float> expected_result{4.0f, 13.0f, 10.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorDivide) {
    tf_core::Polynomial a({3.0f, 6.0f});
    const float b = 3.0f;

    auto div = a / b;

    std::vector<float> expected_result{1.0f, 2.0f};
    EXPECT_EQ(div.GetCoefficients(), expected_result);
}

TEST_F(PolynomialTests, TestOperatorDivideEqual) {
    tf_core::Polynomial a({3.0f, 6.0f});
    const float b = 3.0f;

    a /= b;

    std::vector<float> expected_result{1.0f, 2.0f};
    EXPECT_EQ(a.GetCoefficients(), expected_result);
}