#include <polinoms.h>

#include <gtest.h>



TEST(test_monomial, can_create_monomial_with_S)
{
    ASSERT_NO_THROW(monom m(5, 200));
}
TEST(test_monomial, can_create_monomial_with_powers)
{
    ASSERT_NO_THROW(monom m(5, 5, 6, 7));
}

TEST(test_monomial, cant_create_monomial_if_power_is_greater_than_the_maximum_power_1)
{
    ASSERT_ANY_THROW(monom m(5, 5, 25, 7));
}

TEST(test_monomial, cant_create_monomial_if_power_is_greater_than_the_maximum_power_2)
{
    ASSERT_ANY_THROW(monom m(5, 9261));
}

TEST(test_monomial, can_get_power_x)
{
    monom m(5, 5, 6, 7);
    EXPECT_EQ(5, m.getX());
}

TEST(test_monomial, can_get_power_y)
{
    monom m(5, 5, 6, 7);
    EXPECT_EQ(6, m.getY());
}

TEST(test_monomial, can_get_power_z)
{
    monom m(5, 5, 6, 7);
    EXPECT_EQ(7, m.getZ());
}

TEST(test_monomial, can_get_coefficient)
{
    monom m(5, 5, 6, 7);
    EXPECT_EQ(5, m.getCoeff());
}

TEST(test_monomial, can_compare_the_monomials_for_equality)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 == m2);
}

TEST(test_monomial, can_compare_the_monomials_on_inequality)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 != m2);
}

TEST(test_monomial, can_compare_the_monomials_less)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 6, 6, 8);
    EXPECT_EQ(true, m1 < m2);
}

TEST(test_monomial, can_compare_the_monomials_less_or_equal_1)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 6, 6, 8);
    EXPECT_EQ(true, m1 <= m2);
}

TEST(test_monomial, can_compare_the_monomials_less_or_equal_2)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 <= m2);
}

TEST(test_monomial, can_compare_the_monomials_greater)
{
    monom m1(5, 6, 9, 7);
    monom m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 > m2);
}

TEST(test_monomial, can_compare_the_monomials_greater_or_equal_1)
{
    monom m1(5, 5, 9, 7);
    monom m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 >= m2);
}

TEST(test_monomial, can_compare_the_monomials_greater_or_equal_2)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 >= m2);
}

TEST(test_monomial, can_multiply_by_a_scalar_1)
{
    monom m(5, 5, 6, 7);
    int scl = 10;
    m = m * scl;
    EXPECT_EQ(50, m.getCoeff());
}

TEST(test_monomial, can_multiply_by_a_scalar_2)
{
    monom m(5, 5, 6, 7);
    int scl = 10;
    m *= scl;
    EXPECT_EQ(50, m.getCoeff());
}

TEST(test_monomial, can_add_monomials_1)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m3(0, 0);
    m3 = m1 + m2;
    EXPECT_EQ(10, m3.getCoeff());
}

TEST(test_monomial, can_add_monomials_2)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m(5, 10, 12, 14);
    m1 += m2;
    EXPECT_EQ(10, m1.getCoeff());
}

TEST(test_monomial, cant_add_monomials_if_different_power_of_monomials)
{
    monom m1(5, 5, 9, 7);
    monom m2(5, 10, 6, 7);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(test_monomial, can_subtract_monomials_1)
{
    monom m1(10, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m3(0, 0);
    m3 = m1 - m2;
    EXPECT_EQ(5, m3.getCoeff());
}

TEST(test_monomial, can_subtract_monomials_2)
{
    monom m1(10, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m(5, 10, 12, 14);
    m1 -= m2;
    EXPECT_EQ(5, m1.getCoeff());
}

TEST(test_monomial, cant_subtract_monomials_if_different_power_of_monomials)
{
    monom m1(10, 5, 9, 7);
    monom m2(5, 10, 6, 7);
    ASSERT_ANY_THROW(m1 - m2);
}

TEST(test_monomial, can_multiply_monomials_1)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m3(0, 0);
    monom m(25, 10, 12, 14);
    m3 = m1 * m2;
    EXPECT_EQ(m, m3);
    EXPECT_EQ(m.getCoeff(), m3.getCoeff());
}

TEST(test_monomial, can_multiply_monomials_2)
{
    monom m1(5, 5, 6, 7);
    monom m2(5, 5, 6, 7);
    monom m3(0, 0);
    monom m(25, 10, 12, 14);
    m1 *= m2;
    EXPECT_EQ(m, m1);
    EXPECT_EQ(m.getCoeff(), m1.getCoeff());
}

TEST(test_monomial, cant_multiply_monomials_if_resulting_power_exceeds_the_maximum)
{
    monom m1(10, 5, 17, 7);
    monom m2(5, 10, 6, 5);
    ASSERT_ANY_THROW(m1 * m2);
}
TEST(test_monomial, can_change_the_sign_of_the_coefficient_monomials)
{
    monom m(10, 5, 9, 7);
    m = -m;
    EXPECT_EQ(-10, m.getCoeff());
}


