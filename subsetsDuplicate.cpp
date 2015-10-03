#include "stdafx.h"
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > results;
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		vector<int> v(S);
		sort(v.begin(), v.end());
		vector<int> vec;
		subsets(0, vec, v);
		return results;
	}

	void subsets(int pos, vector<int> &curSet, const vector<int> &S)
	{
		results.push_back(curSet);
		for (int i = pos; i < S.size(); ++i)
		{
			if (i != pos && S[i - 1] == S[i])
				continue;
			curSet.push_back(S[i]);
			subsets(i + 1, curSet, S);
			curSet.pop_back();
		}
	}
};
