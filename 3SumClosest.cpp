class Solution
{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		sort(num.begin(), num.end());

		int closest = num[0] + num[1] + num[2];

		for (int i = 0; i < num.size() - 2; ++i)
		{
			if (i > 0 && num[i] == num[i - 1]) // Ìø¹ıÖØ¸´ÔªËØ
				continue;

			int l = i + 1, r = num.size() - 1;
			while (l < r)
			{
				if (abs(num[i] + num[l] + num[r] - target) < abs(closest - target))
					closest = num[i] + num[l] + num[r];

				if (num[l] + num[r] == target - num[i])
					return target;
				else if (num[l] + num[r] > target - num[i])
					--r;
				else
					++l;
			}
		}

		return closest;
	}
};