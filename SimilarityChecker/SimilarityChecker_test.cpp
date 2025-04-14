#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
};

TEST_F(SimilarityCheckerFixture, LengthScore_SameLength)
{
	SimilarityChecker sc{ "ADS", "DSA" };
	int result = sc.checkLength();
	EXPECT_EQ(result, 60);
}


TEST_F(SimilarityCheckerFixture, LengthScore_PartialScore1)
{
	SimilarityChecker sc{ "A", "BB" };
	int result = sc.checkLength();
	int expected = (1.0 - static_cast<double>(1) / 1) * 60;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, LengthScore_PartialScore2)
{
	SimilarityChecker sc{ "AAABB", "BAA" };
	int result = sc.checkLength();
	int expected = (1.0 - static_cast<double>(2) / 3) * 60;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, LengthScore_PartialScore3)
{
	SimilarityChecker sc{ "AA", "AAE" };
	int result = sc.checkLength();
	int expected = (1.0 - static_cast<double>(1) / 2) * 60;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, LengthScore_DoubleLengthDiff_ZeroScore)
{
	SimilarityChecker sc{ "AA", "AAEEEE" };
	int result = sc.checkLength();
	EXPECT_EQ(result, 0);
}

TEST_F(SimilarityCheckerFixture, AlphaScore_FullMatch)
{
	SimilarityChecker sc{ "ASD", "DSA" };
	int result = sc.checkAlpha();
	EXPECT_EQ(result, 40);
}

TEST_F(SimilarityCheckerFixture, AlphaScore_NoOverlap)
{
	SimilarityChecker sc{ "A", "BB" };
	int result = sc.checkAlpha();
	EXPECT_EQ(result, 0);
}

TEST_F(SimilarityCheckerFixture, AlphaScore_PartialOverlap_FullSameUsed)
{
	SimilarityChecker sc{ "AAABB", "BA" };
	int result = sc.checkAlpha();
	int expected = static_cast<double>(2) / 2 * 40;
	EXPECT_EQ(result, expected);
}

TEST_F(SimilarityCheckerFixture, AlphaScore_PartialOverlap_OneMatch)
{
	SimilarityChecker sc{ "AA", "AAE" };
	int result = sc.checkAlpha();
	int expected = static_cast<double>(1) / 2 * 40;
	EXPECT_EQ(result, expected);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}