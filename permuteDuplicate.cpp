#include "stdafx.h"
class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: A list of unique permutations.
	*/
	vector<vector<int> > permuteUnique(vector<int> &nums) {
		// write your code here
		vector<vector<int> > results;
		vector<int> S(nums);
		vector<int> curList;
		sort(S.begin(), S.end());
		vector<bool> used(nums.size());
		permute(results, S, used, curList);
		return results;
	}

	void permute(vector<vector<int> > &results, vector<int> &nums, vector<bool> &used, vector<int> &curList)
	{
		if (curList.size() == nums.size())
			results.push_back(curList);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (used[i] || (i != 0 && nums[i] == nums[i - 1] && !used[i - 1]))
				continue;
			used[i] = true;
			curList.push_back(nums[i]);
			permute(results, nums, used, curList);
			curList.pop_back();
			used[i] = false;
		}
	}

};