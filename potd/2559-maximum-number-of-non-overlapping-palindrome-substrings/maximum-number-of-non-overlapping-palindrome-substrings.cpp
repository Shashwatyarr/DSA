class Solution {
public:
    vector<vector<int>> p;
    vector<int> dp;

    int f(string &s, int i, int j) {
        if (i > j) return 1;
        if (i == j) return p[i][j] = 1;
        if (p[i][j] != -1)
            return p[i][j];
        if (s[i] != s[j])
            return p[i][j] = 0;
        return p[i][j] = f(s, i + 1, j - 1);
    }

    int solve(string &s, int i, int k) {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = solve(s, i + 1, k);
        for (int j = i + k - 1; j < s.size(); j++) {
            if (p[i][j]) {
                ans = max(ans, 1 + solve(s, j + 1, k));
            }
        }
        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        p.assign(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                f(s, i, j);
            }
        }
        dp.assign(n, -1);
        return solve(s, 0, k);
    }
};