class Solution {
public:
    long long mod = 1e9 + 7;
    long long dp[1005][1005][2];
    int solve(int idx, bool st, int n, int k) {
        if (k == 0) return 1;
        if (idx == n) return 0;
        if (dp[idx][k][st] != -1)
            return dp[idx][k][st];
        long long take = 0, notTake = 0;
        if (st) {
            take = solve(idx, false, n, k - 1);
            notTake = solve(idx + 1, true, n, k);
        }
        else {
            take = solve(idx+1, true, n, k);
            notTake = solve(idx + 1, false, n, k);
        }
        return dp[idx][k][st] = (take + notTake) % mod;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, false, n, k);
    }
};