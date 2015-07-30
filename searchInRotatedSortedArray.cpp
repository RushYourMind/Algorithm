#include "stdafx.h"
#include "searchInRotatedSortedArray.h"

//http://www.cnblogs.com/boring09/p/4243763.html
//这种思路比较清晰，循环中第二个if判断的时候，把情况分为两大类：即结果在左半边以及结果在右半边
//如果把情况分为target与中位数相比，则情况比较复杂
//例如http://www.makuiyu.cn/2015/01/LeetCode_33.%20Search%20in%20Rotated%20Sorted%20Array/ 中的第一种解法
//其中的第二种解法思路更加清晰,见下面注释代码
int Solution33::search(vector<int>& nums, int target)
{

	int n = nums.size();
	int l = 0, r = n - 1;

	while (l <= r)
	{
		int middle = (l + r) / 2;
		if (target == nums[middle])
			return middle;

		if (nums[middle] > nums[l] && (target >= nums[l] &&target< nums[middle]) 
			|| (nums[middle] < nums[l]) && (target >= nums[l] || target < nums[middle]))
			r = middle - 1;
		else
			l = middle + 1;
	}
	return -1;
}


//class Solution
//{
//public:
//	int search(int A[], int n, int target)
//	{
//		int l = 0, r = n - 1;
//		while (l <= r)
//		{
//			int m = (l + r) / 2;
//			if (A[m] == target)
//				return m;
//			if (A[l] <= A[m])
//			{
//				if (A[l] <= target && target < A[m])
//					r = m - 1;
//				else
//					l = m + 1;
//			}
//			else
//			{
//				if (A[m] < target && target <= A[r])
//					l = m + 1;
//				else
//					r = m - 1;
//			}
//		}
//
//		return -1;
//	}
//};
