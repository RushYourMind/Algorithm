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
			if (s[l] == s[r])//��������ǵ�һ����ĸ�����һ����ĸ��ͬ�������ǰ��һ����set�е�Ԫ�ز���
				l++;
			else//������ǵ�һ����ĸ�����һ����ĸ��ͬ����ʾ�ҵ��˵��е�Ԫ�أ������¶�λl��λ��
			{
				cset.clear();
				r = l;
				++l;
				len = 0;
			}
		}
		r++;
	}
	//���һ·���ף�û�о���else��֧����longestû�б�����
	if (len > longest)
		longest = len;
	return longest;
}

//һ�ָ����ķ�ʽ
int Solution3::lengthOfLongestSubstring2(string s)
{
	map<char, int> myMap;
	int lastRepeatPosition = -1;
	int i = 0;
	int maxLen = 0;
	while (i<s.size())
	{
		if (myMap.find(s[i]) != myMap.end() && lastRepeatPosition<myMap[s[i]])//�ҵ����ظ�����ĸ
		{
			lastRepeatPosition = myMap[s[i]];

		}
		if (i - lastRepeatPosition > maxLen)
			maxLen = i - lastRepeatPosition;
		myMap[s[i]] = i;//ÿ�ζ�������ĸ��index���ظ�����ĸ��index�ᱻ������ֵ���ĸ������

		++i;//
	}
	return maxLen;
}

//û��ʹ��map�İ汾
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