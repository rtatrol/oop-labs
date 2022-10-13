#include "pch.h"
#include "../BigInt.h"

TEST(TestBigInt, TestEqualityComparator) {
	BigInt first("12345122121312"), second("532115312112"),third("532115312112");
	EXPECT_TRUE(second==third);
	EXPECT_FALSE(first == second);
}

TEST(TestBigInt, TestLessComparator) {
	BigInt first("12345122121312"), second("532115");
	EXPECT_TRUE(second<first);
	EXPECT_FALSE(first<second);
}

TEST(TestBigInt, TestMoreComparator) {
	BigInt first("12345122121312"), second("532115");
	EXPECT_TRUE(first>second);
	EXPECT_FALSE(second>first);
}

TEST(TestBigInt, TestInequalityComparator) {
	BigInt first("12345122121312"), second("532115312112"), third("532115312112");
	EXPECT_TRUE(first != second);
	EXPECT_FALSE(second != third);
}

TEST(TestBigInt, TestLessOrEqualityComparator) {
	BigInt first("12345122121312"), second("532115"),third("532115");
	EXPECT_TRUE(second <= third);
	EXPECT_FALSE(first <= second);
}

TEST(TestBigInt, TestMoreOrEqualityComparator) {
	BigInt first("12345122121312"), second("532115"), third("532115");
	EXPECT_TRUE(second >= third);
	EXPECT_FALSE(second>=first);
}

TEST(TestBigInt, TestAssignOperator) {
	BigInt first("532115"), second("532115"),third("676543245342");
	EXPECT_TRUE(first == second);
	first = third;
	EXPECT_FALSE(first == second);
}

TEST(TestBigInt, TestBitInversOperator) {
	BigInt first(52), second(203), third(10);
	EXPECT_TRUE((~first) == second);
	EXPECT_FALSE((~first) == third);
}

TEST(TestBigInt, TestUnarPlusOperator) {
	BigInt first("532115"), second("532115"), third("-532115");
	EXPECT_TRUE(first == second);
	first = third;
	EXPECT_FALSE(first == second);
}

TEST(TestBigInt, TestUnarMinusOperator) {
	BigInt first("532115"), second("532115"), third("-532115");
	EXPECT_TRUE(-first == third);
	EXPECT_FALSE(-first == second);
}

TEST(TestBigInt, TestPlusOperator) {
	BigInt first(0), second("532115111111"), third("-532115111111");
	EXPECT_TRUE(first==(second+third));
	EXPECT_FALSE(second==(first+third));
}

TEST(TestBigInt, TestMinusOperator) {
	BigInt first(1), second("532115111111"), third("532115111110");
	EXPECT_TRUE(first == (second - third));
	EXPECT_FALSE(second == (third-first));
}

TEST(TestBigInt, TestMultOperator) {
	BigInt first(1), second("532115111111"), third("532115111111");
	EXPECT_TRUE(second == (first*third));
	EXPECT_FALSE(first == (third*second));
}

TEST(TestBigInt, TestDivisionOperator) {
	BigInt first(1), second("532115111112"), third("532115111111");
	EXPECT_TRUE(second != (third/first));
	EXPECT_FALSE(first == (third/second));
}

TEST(TestBigInt, TestRemainsOperator) {
	BigInt first(1), second("532115111112"), third("532115111111");
	EXPECT_TRUE(second != (third % first));
	EXPECT_FALSE(first == (third % second));
}

TEST(TestBigInt, TestXorOperator) {
	BigInt first(1), second("532115111112"), third("532115111111");
	EXPECT_TRUE(second != (third ^ first));
	EXPECT_FALSE(first == (third ^ second));
}

TEST(TestBigInt, TestAndOperator) {
	BigInt first(1), second("532115111112"), third("532115111111");
	EXPECT_TRUE(second != (third & first));
	EXPECT_FALSE(first == (third & second));
}

TEST(TestBigInt, TestOrOperator) {
	BigInt first(1), second("532115111112"), third("532115111111");
	EXPECT_TRUE(second != (third | first));
	EXPECT_FALSE(first == (third | second));
}

TEST(TestBigInt, TestIncrementPrefOperator) {
	BigInt first("738162874107468821"), second("738162874107468820");
	EXPECT_TRUE(first == ++second);
}

TEST(TestBigInt, TestIncrementPostfOperator) {
	BigInt first("738162874107468821"), second("738162874107468820");
	EXPECT_FALSE(first == second++);
}

TEST(TestBigInt, TestDecrementPrefOperator) {
	BigInt first("738162874107468820"), second("738162874107468821");
	EXPECT_TRUE(first == --second);
}

TEST(TestBigInt, TestDecrementPostfOperator) {
	BigInt first("738162874107468820"), second("738162874107468821");
	EXPECT_FALSE(first == second--);
}
