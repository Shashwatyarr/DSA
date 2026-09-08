class Solution {
    vector<vector<vector<int>>> dp;
    char keyboard[5][6];
    vector<pair<int, int>> mp;
public:
    int find(string& word, int i, int h1, int h2) {
        if (i >= word.size())
            return 0;
        if (dp[i][h1][h2] != -1)
            return dp[i][h1][h2];
        int curr = word[i] - 'A';
        int d1 = 0, d2 = 0;
        if (h1 != 26)
            d1 = abs(mp[h1].first - mp[curr].first) +
                 abs(mp[h1].second - mp[curr].second);
        if (h2 != 26)
            d2 = abs(mp[h2].first - mp[curr].first) +
                 abs(mp[h2].second - mp[curr].second);
        return dp[i][h1][h2] =
                   min((find(word, i + 1, curr, h2) + d1),
                       (find(word, i + 1, h1, curr) + d2));
    }

    int minimumDistance(string word) {
        int n = word.size();
        int count = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                if (count == 26)
                    break;
                mp.push_back({i, j});
                count++;
            }
            if (count == 26)
                break;
        }
        dp.resize(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return find(word, 0, 26, 26);
    }
};