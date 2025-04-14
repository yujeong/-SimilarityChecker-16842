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

		longLen = longStr.length();
		shortLen = shortStr.length();
	}
	
	int checkLength()
	{
		if (longLen >= shortLen * 2)
			return 0;

		int gap = longLen - shortLen;
		return (1.0 - static_cast<double>(gap) / shortLen) * 60;
	}

	int checkAlpha()
	{
		unordered_set<char> longSet(longStr.begin(), longStr.end());
		unordered_set<char> shortSet(shortStr.begin(), shortStr.end());

		int sameCnt = 0;
		for (char ch : longSet) {
			if (shortSet.count(ch)) {
				sameCnt++;
			}
		}

		unordered_set<char> totalSet = longSet;
		totalSet.insert(shortSet.begin(), shortSet.end());
		int totalCnt = totalSet.size();

		if (totalCnt == 0) return 0;

		return static_cast<double>(sameCnt) / totalCnt * 40;
	}

private:
	string longStr;
	string shortStr;
	int longLen;
	int shortLen;
};