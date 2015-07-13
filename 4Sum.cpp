#include "stdafx.h"
#include "4Sum.h"

vector<vector<int> > Solution18::fourSum(vector<int> &nums, int target)
{
	vector<vector<int> > v;
	if (nums.size() == 0)
		return v;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size()-3 && nums[i]+nums[i+1]+nums[i+2]+nums[i+3]<=target; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i+1; j < nums.size() - 2 && nums[i] + nums[j] + nums[j + 1] + nums[j + 2] <= target; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			int l = j+1, r = nums.size() - 1;
			while (l < r)
			{
				if (nums[l] + nums[r] == target - nums[i] - nums[j])
				{
					v.push_back({ nums[i], nums[j], nums[l], nums[r] });
					while (++l < r && nums[l] == nums[l - 1]);
					while (l < --r && nums[r] == nums[r + 1]);
				}
				else if (nums[l] + nums[r] > target - nums[i] - nums[j])
					r--;
				else
					l++;
			}

		}
	}
	return v;
}