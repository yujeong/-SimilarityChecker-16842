#include <iostream>
#include <unordered_set>

using namespace std;

class SimilarityChecker
{
public:
	SimilarityChecker(const string& a, const string& b)
	{
		if (a.length() >= b.length()) {
			longStr = a;
			shortStr = b;
		}
		else {
			longStr = b;
			shortStr = a;
		}
	}
	
	int checkLength()
	{
		int longLen = longStr.length();
		int shortLen = shortStr.length();

		if (longLen >= shortLen * 2)
			return 0;

		int gap = longLen - shortLen;
		return (1.0 - static_cast<double>(gap) / shortLen) * 60;
	}

	int checkAlpha()
	{
		int sameCnt = getSameAlphaCount();
		int totalCnt = getTotalAlphaCount();

		if (totalCnt == 0) return 0;

		return static_cast<double>(sameCnt) / totalCnt * 40;
	}

	int getSameAlphaCount()
	{
		unordered_set<char> longSet(longStr.begin(), longStr.end());
		unordered_set<char> shortSet(shortStr.begin(), shortStr.end());

		int sameCnt = 0;
		for (char ch : longSet) {
			if (shortSet.count(ch)) {
				sameCnt++;
			}
		}
		return sameCnt;
	}

	int getTotalAlphaCount()
	{
		unordered_set<char> longSet(longStr.begin(), longStr.end());
		unordered_set<char> shortSet(shortStr.begin(), shortStr.end());

		unordered_set<char> totalSet = longSet;
		totalSet.insert(shortSet.begin(), shortSet.end());
		return totalSet.size();
	}


private:
	string longStr;
	string shortStr;
};