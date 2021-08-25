#include "gtest/gtest.h"

#include <memory>

#include "discretization_method.hpp"
#include "polynomial_discretizer.hpp"

/**************** Polynomial Discretizer ****************/
class PolynomialDiscretizerTests : public ::testing::TestWithParam<tf_core::DiscretizationMethod>
{
    protected:
        void SetUp(void) override
        {}

        void TearDown(void) override
        {}
};

TEST_P(PolynomialDiscretizerTests, TestConstructor) {
    EXPECT_NO_THROW(auto polynomial_discretizer = tf_core::PolynomialDiscretizer());
}

TEST_P(PolynomialDiscretizerTests, TestZeroOrderPolynomial) {
    auto polynomial = tf_core::Polynomial({1.0f});
    auto discretization_time = 0.5f;
    auto method = GetParam();

    auto [num, den] = tf_core::PolynomialDiscretizer::Discretize(polynomial, discretization_time, method);

    switch (GetParam()) {
        case tf_core::DiscretizationMethod::Forward:
        {
            EXPECT_EQ(num, polynomial);
            EXPECT_EQ(den, tf_core::Polynomial({1.0f}));
            break;
        }
        case tf_core::DiscretizationMethod::Backward:
        {
            EXPECT_EQ(num, polynomial);
            EXPECT_EQ(den, tf_core::Polynomial({1.0f}));
            break;
        }
        case tf_core::DiscretizationMethod::Tustin:
        {
            EXPECT_EQ(num, polynomial);
            EXPECT_EQ(den, tf_core::Polynomial({1.0f}));
            break;
        }
    }
}

INSTANTIATE_TEST_CASE_P(
    PolynomialDiscretizerTestsMethods,
    PolynomialDiscretizerTests,
    ::testing::Values(
        tf_core::DiscretizationMethod::Forward,
        tf_core::DiscretizationMethod::Backward,
        tf_core::DiscretizationMethod::Tustin
    )
);
