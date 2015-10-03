#include "stdafx.h"
class Solution{
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int> > permute(vector<int> nums) {
		vector<vector<int> > results;
		if (nums.size() == 0)
			return results;
		vector<bool> used(nums.size());
		vector<int> curList;
		helper(results, nums, curList, used);
		return results;
	}

	void helper(vector<vector<int> > &results, vector<int> &nums, vector<int> &curList, vector<bool> &used)
	{
		if (curList.size() == nums.size())
			results.push_back(curList);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (used[i])
				continue;
			//if (find(curList.begin(), curList.end(), nums[i]) != curList.end())
			//	continue;
			used[i] = true;
			curList.push_back(nums[i]);
			helper(results, nums, curList, used);
			curList.pop_back();
			used[i] = false;

		}
	}
};

