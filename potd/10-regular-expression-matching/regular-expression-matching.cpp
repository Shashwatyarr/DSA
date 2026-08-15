class Solution {
public:
    vector<vector<int>> dp;

    bool find(string& s, string& p, int i, int j) {
        if(j<0) return i<0;
        if(i<0) {
            if(p[j]=='*')
            return find(s,p,i,j-2);
            return 0;
        }

        if (i == 0 && j == 0 && (s[i] == p[j] || p[j]=='.')) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j]) return dp[i][j] = find(s, p, i - 1, j - 1);

        if (p[j] == '*') {
            int a=find(s,p,i,j-2);
            int b=0;
            if(p[j-1] == s[i] || p[j-1] == '.')
            b=find(s,p,i-1,j);
            return dp[i][j]=a||b;
        }

        if (p[j] == '.') return dp[i][j] = find(s, p, i - 1, j - 1);

        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return find(s, p, n - 1, m - 1);
    }
};