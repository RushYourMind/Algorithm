#include "stdafx.h"
#include "removeDuplicates.h"

int Solution26::removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	int i = 1;
	int  l = 0;
	while (i<nums.size())
	{
		if (nums[l] != nums[i])
		{
			nums[l + 1] = nums[i];
			l++;
		}
		i++;
	}
	
	return l+1;
}