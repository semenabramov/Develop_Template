#include "roman.h"

#include <gtest.h>

TEST(test_converter, test_roman_one)
{
	roman rm("I");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(1, v.value);
}

TEST(test_converter, test_roman_four)
{
	roman rm("IV");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(4, v.value);
}

TEST(test_converter, test_roman_five)
{
	roman rm("V");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(5, v.value);
}

TEST(test_converter, test_roman_six)
{
	roman rm("VI");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(6, v.value);
}

TEST(test_converter, test_roman_nine)
{
	roman rm("IX");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(9, v.value);
}

TEST(test_converter, test_roman_ten)
{
	roman rm("X");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(10, v.value);
}

TEST(test_converter, test_roman_eleven)
{
	roman rm("XI");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(11, v.value);
}

TEST(test_converter, test_roman_forty)
{
	roman rm("XL");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(40, v.value);
}

TEST(test_converter, test_roman_fifty)
{
	roman rm("L");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(50, v.value);
}

TEST(test_converter, test_roman_sixty)
{
	roman rm("LX");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(60, v.value);
}

TEST(test_converter, test_roman_ninety)
{
	roman rm("XC");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(90, v.value);
}

TEST(test_converter, test_roman_hundred)
{
	roman rm("C");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(100, v.value);
}

TEST(test_converter, test_roman_one_hundred_and_ten)
{
	roman rm("CX");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(110, v.value);
}

TEST(test_converter, test_roman_four_hundred)
{
	roman rm("CD");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(400, v.value);
}

TEST(test_converter, test_roman_five_hundred)
{
	roman rm("D");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(500, v.value);
}

TEST(test_converter, test_roman_six_hundreds)
{
	roman rm("DC");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(600, v.value);
}

TEST(test_converter, test_roman_nine_hundred)
{
	roman rm("CM");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(900, v.value);
}

TEST(test_converter, test_roman_thousand)
{
	roman rm("M");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(1000, v.value);
}

TEST(test_converter, test_roman_one_thousand_one_hundred)
{
	roman rm("MC");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(1100, v.value);
}

TEST(test_converter, test_roman_one_thousand_six_hundred_and_forty_seven)
{
	roman rm("MDCXLVII");
	Convertor conv(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(1647, v.value);
}

TEST(test_converter, test_arabic_one)
{
	arabic ar(1);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("I", v.value);
}

TEST(test_converter, test_arabic_four)
{
	arabic ar(4);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("IV", v.value);
}

TEST(test_converter, test_arabic_five)
{
	arabic ar(5);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("V", v.value);
}

TEST(test_converter, test_arabic_six)
{
	arabic ar(6);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("VI", v.value);
}

TEST(test_converter, test_arabic_nine)
{
	arabic ar(9);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("IX", v.value);
}

TEST(test_converter, test_arabic_ten)
{
	arabic ar(10);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("X", v.value);
}

TEST(test_converter, test_arabic_eleven)
{
	arabic ar(11);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("XI", v.value);
}

TEST(test_converter, test_arabic_forty)
{
	arabic ar(40);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("XL", v.value);
}

TEST(test_converter, test_arabic_fifty)
{
	arabic ar(50);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("L", v.value);
}

TEST(test_converter, test_arabic_sixty)
{
	arabic ar(60);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("LX", v.value);
}

TEST(test_converter, test_arabic_ninety)
{
	arabic ar(90);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("XC", v.value);
}

TEST(test_converter, test_arabic_hundred)
{
	arabic ar(100);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("C", v.value);
}

TEST(test_converter, test_arabic_one_hundred_and_ten)
{
	arabic ar(110);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("CX", v.value);
}

TEST(test_converter, test_arabic_four_hundred)
{
	arabic ar(400);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("CD", v.value);
}

TEST(test_converter, test_arabic_five_hundred)
{
	arabic ar(500);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("D", v.value);
}

TEST(test_converter, test_arabic_six_hundreds)
{
	arabic ar(600);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("DC", v.value);
}

TEST(test_converter, test_arabic_nine_hundred)
{
	arabic ar(900);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("CM", v.value);
}

TEST(test_converter, test_arabic_thousand)
{
	arabic ar(1000);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("M", v.value);
}

TEST(test_converter, test_arabic_one_thousand_one_hundred)
{
	arabic ar(1100);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("MC", v.value);
}

TEST(test_converter, test_arabic_one_thousand_six_hundred_and_forty_seven)
{
	arabic ar(1647);
	Convertor conv(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("MDCXLVII", v.value);
}

TEST(test_converter, test_setArabic)
{
	arabic ar(2547);
	Convertor conv;
	conv.setArabic(ar);
	roman v = conv.get_roman();
	EXPECT_EQ("MMDXLVII", v.value);
}

TEST(test_converter, test_setRoman)
{
	roman rm("MMMCDLXXXI");
	Convertor conv;
	conv.setRoman(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(3481, v.value);
}

TEST(test_converter, throw_getArabic_if_the_Arabic_is_not_ready)
{
	Convertor conv;
	ASSERT_ANY_THROW(conv.get_arabic());
}

TEST(test_converter, throw_getRoman_if_the_Roman_is_not_ready)
{
	Convertor conv;
	ASSERT_ANY_THROW(conv.get_roman());
}

TEST(test_converter, can_convert_Roman_if_lowercase_letters)
{
	roman rm("MmMCDlxXi");
	Convertor conv;
	conv.setRoman(rm);
	arabic v = conv.get_arabic();
	EXPECT_EQ(3471, v.value);
}

TEST(test_converter, throw_if_invalid_characters)
{
	roman rm("Mm5MhCDlvaxXi");
	Convertor conv;
	ASSERT_ANY_THROW(conv.setRoman(rm));
}