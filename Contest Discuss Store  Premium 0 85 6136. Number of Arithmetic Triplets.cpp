// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
public:
    int arithmeticTriplets(vector<int> &nums, int diff)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                        ans++;
                }
            }
        }
        return ans;
    }
};