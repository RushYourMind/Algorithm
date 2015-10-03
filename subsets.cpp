#include "stdafx.h"
class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > results;
	vector<vector<int> > subsets(vector<int> &nums) {
		// write your code here
		if (nums.size() == 0)
			return results;

		vector<int> curSet;
		subsetsHelper(0, nums, curSet);
		return results;
	}

	void subsetsHelper(int pos, vector<int> &nums, vector<int> &curSet)
	{

		results.push_back(curSet);
		for (int i = pos; i < nums.size(); ++i)
		{
			curSet.push_back(nums[i]);
			subsetsHelper(i + 1, nums, curSet);
			curSet.pop_back();
		}
	}

};
