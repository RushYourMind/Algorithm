#include "findMedianSortedArray.h"
#include <algorithm>

double Solution4::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int k = nums1.size() + nums2.size();

	if (k % 2 == 1)
		return findKth(nums1, 0, nums2,0, k / 2 + 1);
	else
		return (findKth(nums1, 0, nums2, 0, k / 2 ) + findKth(nums1, 0, nums2, 0, k / 2 + 1))/2.0;
}

double Solution4::findKth(vector<int>& a, int b1, vector<int>& b, int b2, int k)
{

	//ensure size of a is smaller than b
	if (a.size() - b1 > b.size() - b2)
		return findKth(b, b2, a, b1, k);

	if (a.size() - b1 == 0)
		return b[b2 + k - 1];
	if (k == 1)
		return min(a[b1], b[b2]);


	int lena = a.size() - b1;
	int pa = min(k / 2,(int)a.size()-b1); 
	int pb = k - pa;
	if(a[b1+pa-1] == b[b2+pb-1])
		return a[b1+pa-1];
	else if (a[b1 + pa - 1] < b[b2 + pb - 1])
	{
		return findKth(a, b1 + pa, b, b2, k - pa);
	}
	else
	{
		return findKth(a, b1, b, b2+pb, k - pb);
	}

}