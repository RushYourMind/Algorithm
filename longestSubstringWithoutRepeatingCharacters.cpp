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

//一种更简洁的方式
int Solution3::lengthOfLongestSubstring2(string s)
{
	map<char, int> myMap;
	int lastRepeatPosition = -1;
	int i = 0;
	int maxLen = 0;
	while (i<s.size())
	{
		if (myMap.find(s[i]) != myMap.end() && lastRepeatPosition<myMap[s[i]])//找到了重复的字母
		{
			lastRepeatPosition = myMap[s[i]];

		}
		if (i - lastRepeatPosition > maxLen)
			maxLen = i - lastRepeatPosition;
		myMap[s[i]] = i;//每次都更新字母的index，重复的字母的index会被后面出现的字母所覆盖

		++i;//
	}
	return maxLen;
}

//没有使用map的版本
int lengthOfLongestSubstring(string s) {
	const int MAX_CHARS = 256;
	int m[MAX_CHARS];
	memset(m, -1, sizeof(m));

	int maxLen = 0;
	int lastRepeatPos = -1;
	for (int i = 0; i<s.size(); i++) {
		if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
			lastRepeatPos = m[s[i]];
		}
		if (i - lastRepeatPos > maxLen) {
			maxLen = i - lastRepeatPos;
		}
		m[s[i]] = i;
	}
	return maxLen;
}