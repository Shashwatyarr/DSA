class Solution
{
public:
    int qt(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
    {
        if (i == a.size() - 1)
            return a[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        return dp[i][j] = min(qt(i + 1, j, a, dp), qt(i + 1, j + 1, a, dp)) + a[i][j];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        return qt(0, 0, triangle, dp);
    }
};