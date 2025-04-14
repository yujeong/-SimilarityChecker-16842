#include <iostream>
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

private:
	string longStr;
	string shortStr;
	int longLen;
	int shortLen;
};