#include "gtest/gtest.h"

#include <memory>
#include <vector>

#include "transfer_function.hpp"

class TransferFunctionTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}
};

TEST_F(TransferFunctionTests, TestConstructor) {
    std::vector<float> num = {1.0f};
    std::vector<float> den = {1.0f, 2.0f};
    EXPECT_NO_THROW(auto tf = tf_core::TransferFunction(num, den));
}

TEST_F(TransferFunctionTests, TestGetters) {
    tf_core::TransferFunction::CoefficientsVector num = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den = {1.0f};
    auto tf = tf_core::TransferFunction(num, den);

    EXPECT_EQ(num, tf.GetNum());
    EXPECT_EQ(den, tf.GetDen());
}

TEST_F(TransferFunctionTests, TestEqualOperator) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 2.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    EXPECT_TRUE(a == b);
}

TEST_F(TransferFunctionTests, TestNonEqualOperator) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 3.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    EXPECT_TRUE(a != b);
}

TEST_F(TransferFunctionTests, TestParallelNested) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 3.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    auto connection = a.Parallel(b).Parallel(b);

    tf_core::TransferFunction::CoefficientsVector expected_num = {3.0f, 16.0f, 21.0f};
    tf_core::TransferFunction::CoefficientsVector expected_den = {1.0f, 8.0f, 21.0f, 18.0f};
    auto expected_output = tf_core::TransferFunction(expected_num, expected_den);
    EXPECT_EQ(expected_output, connection);

    auto connection_operator = a + b + b;
    EXPECT_EQ(expected_output, connection_operator);
}

TEST_F(TransferFunctionTests, TestSeriesNested) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 3.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    auto connection = a.Series(b).Series(b);

    tf_core::TransferFunction::CoefficientsVector expected_num = {1.0f};
    tf_core::TransferFunction::CoefficientsVector expected_den = {1.0f, 8.0f, 21.0f, 18.0f};
    auto expected_output = tf_core::TransferFunction(expected_num, expected_den);
    EXPECT_EQ(expected_output, connection);

    auto connection_operator = a * b * b;
    EXPECT_EQ(expected_output, connection_operator);
}

TEST_F(TransferFunctionTests, TestSeriesParallelNested) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 3.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    auto connection = a.Series(b).Parallel(b);

    tf_core::TransferFunction::CoefficientsVector expected_num = {2.0f, 8.0f, 6.0f};
    tf_core::TransferFunction::CoefficientsVector expected_den = {1.0f, 8.0f, 21.0f, 18.0f};
    auto expected_output = tf_core::TransferFunction(expected_num, expected_den);
    EXPECT_EQ(expected_output, connection);

    auto connection_operator = a * b + b;
    EXPECT_EQ(expected_output, connection_operator);
}

TEST_F(TransferFunctionTests, TestFeedbackNegative) {
    tf_core::TransferFunction::CoefficientsVector num_a = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_a = {1.0f, 2.0f};
    auto a = tf_core::TransferFunction(num_a, den_a);

    tf_core::TransferFunction::CoefficientsVector num_b = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den_b = {1.0f, 3.0f};
    auto b = tf_core::TransferFunction(num_b, den_b);

    auto parallel_connection = a.Feedback(b);

    tf_core::TransferFunction::CoefficientsVector expected_num = {1.0f, 3.0f};
    tf_core::TransferFunction::CoefficientsVector expected_den = {2.0f, 5.0f, 6.0f};
    auto expected_output = tf_core::TransferFunction(expected_num, expected_den);

    EXPECT_EQ(expected_output, parallel_connection);
}

TEST_F(TransferFunctionTests, TestDiscretization) {
    tf_core::TransferFunction::CoefficientsVector num = {1.0f};
    tf_core::TransferFunction::CoefficientsVector den = {1.0f, 2.0f};
    auto tf = tf_core::TransferFunction(num, den);

    auto discretization_time = 1.0f;

    // Forward
    auto tf_discrete_forward = tf.Discretize(discretization_time, tf_core::DiscretizationMethod::Forward);
    tf_core::TransferFunction::CoefficientsVector expected_forward_num = {1.0f};
    tf_core::TransferFunction::CoefficientsVector expected_forward_den = {-1.0f, 2.0f};
    EXPECT_EQ(tf_discrete_forward.GetNum(), expected_forward_num);
    EXPECT_EQ(tf_discrete_forward.GetDen(), expected_forward_den);

    // Backward
    auto tf_discrete_backward = tf.Discretize(discretization_time, tf_core::DiscretizationMethod::Backward);
    tf_core::TransferFunction::CoefficientsVector expected_backward_num = {0.0f, 1.0f};
    tf_core::TransferFunction::CoefficientsVector expected_backward_den = {-2.0f, 3.0f};
    EXPECT_EQ(tf_discrete_backward.GetNum(), expected_backward_num);
    EXPECT_EQ(tf_discrete_backward.GetDen(), expected_backward_den);

    // Tustin
    auto tf_discrete_tustin = tf.Discretize(discretization_time, tf_core::DiscretizationMethod::Tustin);
    tf_core::TransferFunction::CoefficientsVector expected_tustin_num = {1.0f, 1.0f};
    tf_core::TransferFunction::CoefficientsVector expected_tustin_den = {-3.0f, 5.0f};
    EXPECT_EQ(tf_discrete_tustin.GetNum(), expected_tustin_num);
    EXPECT_EQ(tf_discrete_tustin.GetDen(), expected_tustin_den);
}
