#include "stdafx.h"
// Count how many 1 in binary representation of a 32-bit integer.
// http://www.lintcode.com/en/problem/count-1-in-binary/
class Solution {
public:
	/**
	* @param num: an integer
	* @return: an integer, the number of ones in num
	*/
	int countOnes1(int num) {
		// write your code here
		int count = 0;
		while (num != 0) {
			if (num % 2 != 0)
				++count;
			num = num / 2;
		}
		return count;
	}

	int countOnes(int num) {
		int count = 0;
		while (num != 0) {
			num = num & (num - 1);
			++count;
		}
		return count;
	}

	// This algorithm used Hamming weight thoughts
	// walk through the process of sample in wiki page, and you will understand
	// https://en.wikipedia.org/wiki/Hamming_weight
	int countOnes(int num) {
		int count = num;
		int a = 0x55555555; //010101010101010101010101010101 
		int b = 0x33333333; //用于相邻的四位相加
		int c = 0x0f0f0f0f;
		int d = 0x00ff00ff;
		int e = 0x0000ffff;
		count = (count & a) + ((count >> 1) & a);
		count = (count & b) + ((count >> 2) & b);
		count = (count & c) + ((count >> 4) & c);
		count = (count & d) + ((count >> 8) & d);
		count = (count & e) + ((count >> 16) & e);
		return count;
	}

};
