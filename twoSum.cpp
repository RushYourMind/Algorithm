#include "stdafx.h"
#include "Solution.h"

vector<int> Solution::twoSum(vector<int> &numbers, int target)
{
	vector<int> result;
	map<int, int> m;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (m.find(target - numbers[i]) == m.end())
		{

			m[numbers[i]] = i;
		}
		else
		{
			result.push_back(m[target - numbers[i]] + 1);
			result.push_back(i + 1);
		}
	}
	return result;
}

