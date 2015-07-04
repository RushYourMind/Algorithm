#include "stdafx.h"
#include "longestSubstringWithoutRepeatingCharacters.h"
#include <set>
int Solution3::lengthOfLongestSubstring(string s)
{

	if (s == "")
		return 0;
	set<char> cset;
	int l = 0, r = 0;
	int i = 0;
	int len = 0;
	int longest = 0;
	while (r < s.length())
	{
		if (cset.find(s[r]) == cset.end())
		{
			cset.insert(s[r]);
			len++;
		}
		else//found
		{
			if (longest < len)
				longest = len;
			if (s[l] == s[r])//这种情况是第一个字母与最后一个字母相同，则左边前进一步，set中的元素不变
				l++;
			else//如果不是第一个字母与最后一个字母相同，表示找到了当中的元素，则重新定位l的位置
			{
				cset.clear();
				r = l;
				++l;
				len = 0;
			}
		}
		r++;
	}
	//如果一路到底，没有经过else分支，则longest没有被更新
	if (len > longest)
		longest = len;
	return longest;
}
