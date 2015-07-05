#include "stdafx.h"
#include "ZigZagConversion .h"

string Solution6::convert(string s, int nRows)
{
	vector<string> v(nRows);
	int j = 0;
	while (j < s.size())
	{
		for (int i = 0; i < nRows && j < s.size(); i++, j++)
		{
			v[i] += s[j];
		}
		for (int i = nRows - 2; i > 0 && j < s.size(); i--, j++)
		{
			v[i] += s[j];
		}
	}
	string rtn = "";
	for (int i = 0; i < nRows; i++)
	{
		rtn += v[i];
	}
	return rtn;
}