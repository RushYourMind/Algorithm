#include "stdafx.h"
#include "generateParenthesis.h"


void Solution22::parnethesis_recursive(int l,int r, vector<string>& vec,string s)
{
	if ( l == 0 && r == 0)
		vec.push_back(s);
	if (l > 0)
		parnethesis_recursive(l - 1, r, vec,s+"(");
	if (l< r && r > 0)
		parnethesis_recursive(l, r-1,vec,s+")");
}

vector<string> Solution22::generateParenthesis(int n)
{
	vector<string> vec;
	parnethesis_recursive(n , n, vec,"");
	return vec;
}