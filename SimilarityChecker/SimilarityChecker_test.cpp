#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
};

TEST_F(SimilarityCheckerFixture, TC1)
{
	SimilarityChecker sc{ "ADS", "DSA" };
	int result = sc.checkLength();
	EXPECT_EQ(result, 60);
}


TEST_F(SimilarityCheckerFixture, TC2)
{
	SimilarityChecker sc{ "A", "BB" };
	int result = sc.checkLength();
	EXPECT_EQ(result, 0);
}

TEST_F(SimilarityCheckerFixture, TC3)
{
	SimilarityChecker sc{ "AAABB", "BAA" };
	int result = sc.checkLength();
	int expected = (1.0 - static_cast<double>(2) / 3) * 60;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, TC4)
{
	SimilarityChecker sc{ "AA", "AAE" };
	int result = sc.checkLength();
	int expected = (1.0 - static_cast<double>(1) / 2) * 60;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, TC5)
{
	SimilarityChecker sc{ "AA", "AAEEEE" };
	int result = sc.checkLength();
	EXPECT_EQ(result, 0);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}