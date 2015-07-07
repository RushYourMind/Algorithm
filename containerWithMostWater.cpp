#include "stdafx.h"
#include "containerWithMostWater.h"

int Solution11::maxArea(vector<int> &height)
{
	int size = height.size();
	int l = 0, r = size - 1;
	int max = 0;
	while (l<r)
	{
		int temp = (r - l)*min(height[l], height[r]);
		if (temp >max)
		{
			max = temp;
		}
		if (height[l] < height[r])
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	return max;
}