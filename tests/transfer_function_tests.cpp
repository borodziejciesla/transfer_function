#include "gtest/gtest.h"

#include <memory>

#include "transfer_function.hpp"

class TransferFunctionTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}

};

TEST_F(TransferFunctionTests, TestConstructor) {
    EXPECT_NO_THROW(auto tf = std::make_unique<tf_core::TransferFunction>());
}
