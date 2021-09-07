#include "gtest/gtest.h"

#include <memory>

#include "complex.hpp"

/********************* Complex Numbers *********************/
class ComplexNumbersTests : public ::testing::Test
{
    protected:
        void SetUp(void) override
        {}

        void TearDown(void) override
        {}
};

TEST_F(ComplexNumbersTests, TestConstructor) {
    auto real = 1.0f;
    auto img = 6.0f;

    auto c = tf_core::Complex(real, img);

    EXPECT_FLOAT_EQ(real, c.Real());
    EXPECT_FLOAT_EQ(img, c.Img());
}

TEST_F(ComplexNumbersTests, TestEqualOperator) {
    auto real = 1.0f;
    auto img = 6.0f;
    auto c = tf_core::Complex(real, img);
    auto d = tf_core::Complex(real, img);

    EXPECT_TRUE(c == d);
    EXPECT_FALSE(c != d);
}

TEST_F(ComplexNumbersTests, TestNonEqualOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    EXPECT_TRUE(c != d);
    EXPECT_FALSE(c == d);
}

TEST_F(ComplexNumbersTests, TestAbsAndPhase) {
    auto real = 1.0f;
    auto img = 6.0f;

    auto c = tf_core::Complex(real, img);
    auto abs = c.Abs();
    auto phase = c.Phase();

    auto expected_abs = 6.082762530298219f;
    auto expected_phase = 1.405647649380270f;

    EXPECT_FLOAT_EQ(abs, expected_abs);
    EXPECT_FLOAT_EQ(phase, expected_phase);
}

TEST_F(ComplexNumbersTests, TestConjugate) {
    auto real = 1.0f;
    auto img = 6.0f;

    auto c = tf_core::Complex(real, img);
    auto conj = c.Conjugate();

    auto expected_conj = tf_core::Complex(real, -img);

    EXPECT_EQ(conj, expected_conj);
}

TEST_F(ComplexNumbersTests, TestPlusOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    auto sum = c + d;

    auto expected_sum = tf_core::Complex(real_c + real_d, img_c + img_d);

    EXPECT_EQ(sum, expected_sum);
}

TEST_F(ComplexNumbersTests, TestPlusEQualOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    c += d;

    auto expected_sum = tf_core::Complex(real_c + real_d, img_c + img_d);

    EXPECT_EQ(c, expected_sum);
}

TEST_F(ComplexNumbersTests, TestMinusOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    auto sum = c - d;

    auto expected_sum = tf_core::Complex(real_c - real_d, img_c - img_d);

    EXPECT_EQ(sum, expected_sum);
}

TEST_F(ComplexNumbersTests, TestMinusEQualOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    c -= d;

    auto expected_sum = tf_core::Complex(real_c - real_d, img_c - img_d);

    EXPECT_EQ(c, expected_sum);
}

TEST_F(ComplexNumbersTests, TestMultiplyOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    auto mul = c * d;
    auto mulf = c * 3.0f;

    auto expected = tf_core::Complex(-29.0f, 11.0f);
    auto expectedf = tf_core::Complex(real_c * 3.0f, img_c * 3.0f);

    EXPECT_EQ(mul, expected);
    EXPECT_EQ(mulf, expectedf);
}

TEST_F(ComplexNumbersTests, TestMultiplyEqualOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    c *= d;

    auto expected = tf_core::Complex(-29.0f, 11.0f);

    EXPECT_EQ(c, expected);

    c *= 3.0f;
    auto expectedf = tf_core::Complex(-29.0f * 3.0f, 11.0f * 3.0f);
    EXPECT_EQ(c, expectedf);
}

TEST_F(ComplexNumbersTests, TestDivideOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    auto div = c / d;
    auto divf = c / 3.0f;

    auto expected = tf_core::Complex(1.192307692307692f, 0.038461538461538f);
    auto expectedf = tf_core::Complex(real_c / 3.0f, img_c / 3.0f);

    EXPECT_EQ(div, expected);
    EXPECT_EQ(divf, expectedf);
}

TEST_F(ComplexNumbersTests, TestDivideEqualOperator) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);
    auto real_d = 1.0f;
    auto img_d = 5.0f;
    auto d = tf_core::Complex(real_d, img_d);

    c /= d;

    auto expected = tf_core::Complex(1.192307692307692f, 0.038461538461538f);

    EXPECT_EQ(c, expected);

    c /= 3.0f;
    auto expectedf = tf_core::Complex(1.192307692307692f / 3.0f, 0.038461538461538f / 3.0f);
    EXPECT_EQ(c, expectedf);
}

TEST_F(ComplexNumbersTests, TestPower) {
    auto real_c = 1.0f;
    auto img_c = 6.0f;
    auto c = tf_core::Complex(real_c, img_c);

    EXPECT_EQ(c.Power(0), tf_core::Complex(1.0f, 0.0f));
    EXPECT_EQ(c.Power(1), tf_core::Complex(1.0f, 6.0f));
    EXPECT_EQ(c.Power(2), tf_core::Complex(-35.0f, 12.0f));
    EXPECT_EQ(c.Power(3), tf_core::Complex(-107.0f, -198.0f));

    EXPECT_EQ(c^0, tf_core::Complex(1.0f, 0.0f));
    EXPECT_EQ(c^1, tf_core::Complex(1.0f, 6.0f));
    EXPECT_EQ(c^2, tf_core::Complex(-35.0f, 12.0f));
    EXPECT_EQ(c^3, tf_core::Complex(-107.0f, -198.0f));
}