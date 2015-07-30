#include "stdafx.h"

#include "searchforaRange.h"

vector<int> Solution34::searchRange(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	int start = -1, end = -1;
	vector<int> vec;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (nums[m] > target)
			r = m - 1;
		else if (nums[m] < target)
			l = m + 1;
		else
		{
			int temp = m;
			while (temp >= 0 && nums[temp] == target)
			{

				temp--;
			}
			start = temp + 1;
			temp = m;
			while (temp < nums.size() && nums[temp] == target)
			{
				temp++;
			}
			end = temp - 1;

			vec.push_back(start);
			vec.push_back(end);
			return vec;
		}
	}
	vec.push_back(-1);
	vec.push_back(-1);
	return vec;
}