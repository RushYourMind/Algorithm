#include "stdafx.h"
class Solution {
	/**
	*@param A : an integer sorted array
	*@param target :  an integer to be inserted
	*return : a list of length 2, [index1, index2]
	*/
public:
	vector<int> searchRange(vector<int> &A, int target) {
		// write your code here
		vector<int> result;
		int startIndex = -1, endIndex = -1;
		if (A.size() == 0)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
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
		if (A[start] == target)
			startIndex = start;
		else if (A[end] == target)
			startIndex = end;
		start = 0;
		end = A.size() - 1;
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				start = mid;
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
		if (A[end] == target)
			endIndex = end;
		else if (A[start] == target)
			endIndex = start;
		result.push_back(startIndex);
		result.push_back(endIndex);
		return result;
	}
};