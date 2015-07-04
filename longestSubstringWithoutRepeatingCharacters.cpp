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
