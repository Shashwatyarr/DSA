class Solution
{
public:
    int mini(int n, vector<int> &costs, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = 1e9;
        if (n >= 1)
            ans = min(ans, mini(n - 1, costs, dp) + costs[n - 1] + 1 * 1);
        if (n >= 2)
            ans = min(ans, mini(n - 2, costs, dp) + costs[n - 1] + 2 * 2);
        if (n >= 3)
            ans = min(ans, mini(n - 3, costs, dp) + costs[n - 1] + 3 * 3);

        return dp[n] = ans;
    }
    int climbStairs(int n, vector<int> &costs)
    {
        vector<int> dp(n + 1, -1);
        return mini(n, costs, dp);
    }
};