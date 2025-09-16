#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            while (i < n && gcd(ans.back(), nums[i]) > 1)
            {
                ans.back() = (lcm(ans.back(), nums[i]));
                i++;
            }
            while (ans.size() > 1 && gcd(ans.back(), ans[ans.size() - 2]) > 1)
            {
                int a = ans.back();
                ans.pop_back();
                int b = ans.back();
                ans.back() = lcm(a, b);
            }
            if (i < n)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};