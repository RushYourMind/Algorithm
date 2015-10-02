#include "stdafx.h"
class Solution {
	/**
	* param A : an integer sorted array
	* param target :  an integer to be inserted
	* return : an integer
	*/
public:
	int searchInsert(vector<int> &A, int target) {
		if (A.size() == 0)
			return 0;
		int start = 0;
		int end = A.size() - 1;
		int mid = -1;
		//find startIndex of the target
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				end = mid;
			}
			else if (A[mid] > target)
			{
				end = mid;
			}
			else
			{
				start = mid;
			}
		}
		if (target > A[end])
			return end + 1;
		else if (target <= A[start])
			return 0;
		else
			return start + 1;
	}
};