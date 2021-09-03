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
