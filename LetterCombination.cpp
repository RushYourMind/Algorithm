#include "stdafx.h"
#include "LetterCombination.h"


vector<string> Solution17::letterCombinations(string digits)
{

	string d[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }, s = "";
	vector<string> v({ "" });
	for (int i = 0; i < digits.size(); ++i)
	{
		vector<string> temp;
		for (int j = 0; j < v.size(); ++j)
			for (int k = 0; k < d[digits[i] - '0'].size(); ++k)
			temp.push_back(v[j] + d[digits[i] - '0'][k]);
		v = temp;
	}
    return v;
}


void Solution17::lc(string digits, int start, string s, string d[])
{
	if (digits.size() == start)
		v.push_back(s);
	else
		for (int  i = 0; i < d[digits[start]-'0'].size(); i++)
		{
			lc(digits, start + 1, s + d[digits[start] - '0'][i], d);
		}
}

vector<string> Solution17::letterCombinations_recursive(string digits)
{
	if (digits == "")
		return v;
	int start = 0;
	string d[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }, s = "";
	lc(digits, start, s, d);
	return v;
}

