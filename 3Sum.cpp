#include "stdafx.h"
#include "3Sum.h"
vector<vector<int> > Solution15::threeSum(vector<int> &num)
{
	vector<vector<int> > result;

	sort(num.begin(), num.end());
	int size = num.size();
	for (int i = 0;i < size-2 && num[i]<=0;++i)
	{
		vector<int> temp;
		if (i>0 && num[i] == num[i - 1])
			continue;

		int l = i + 1, r = size - 1;
		while (l < r)
		{
			if (num[i] + num[l] + num[r] > 0)
				r--;
			else if (num[i] + num[l] + num[r] < 0)
				l++;
			else
			{
				result.push_back({ num[i], num[l], num[r] });
				++l;--r;
				while (l<r && num[l -1] == num[l])
					++l;
				while (l<r && num[r + 1] == num[r])
					--r;
			}

		}

	}
	return result;

}
