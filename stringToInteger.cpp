#include "stdafx.h"
#include "stringToInteger.h"

int Solution8::atoi(const char *str)
{
	int i = 0;
	int num = 0;
	int sign = 1;
	for (; str[i] == ' '; i++);
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		++i;
	}
	else if(str[i] > '9' || str[i] < '0')
		return 0;
	while (str[i]<='9' && str[i]>='0')
	{
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] >= '8'))
			return sign == 1 ? INT_MAX : INT_MIN;
		num = num * 10 + str[i] - '0';
		++i;
	}
	return num*sign;

}