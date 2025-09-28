class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        vector<pair<int, int>> c(s.size() + 1, {0, 0});
        for (int i = 0; i < s.size(); i++)
        {
            c[i + 1] = c[i];
            if (s[i] == 'U')
                c[i + 1].first++;
            if (s[i] == 'D')
                c[i + 1].first--;
            if (s[i] == 'R')
                c[i + 1].second++;
            if (s[i] == 'L')
                c[i + 1].second--;
        }
        map<pair<int, int>, int> mpp;
        for (int i = 0; i <= s.size() - k; i++)
        {
            int x = c[i + k].first - c[i].first;
            int y = c[i + k].second - c[i].second;
            mpp[{x, y}]++;
        }
        return mpp.size();
    }
};