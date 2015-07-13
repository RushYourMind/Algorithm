#include "stdafx.h"
#include "strStr.h"


//find first occurence of needle in haystack
int Solution28::strStr(char *haystack, char *needle)
{
	int l1 = strlen(haystack);
	int l2 = strlen(needle);
	//find the first character
	for (int i = 0,j; i < l1-l2; i++)
	{
		//find every character if equal
		for (j = 0; j<l2 && haystack[i + j] == needle[j];++j);
		if (j == l2)
			return i;
	}
	return -1;
}