class Solution
{
public:
    bool scoreBalance(string s)
    {
        vector<int> pre(s.size(), 0);
        pre[0] = s[0] - 'a' + 1;
        for (int i = 1; i < s.size(); i++)
        {
            pre[i] = pre[i - 1] + s[i] - 'a' + 1;
        }
        for (int i = 0; i < pre.size(); i++)
        {
            if (pre[pre.size() - 1] - pre[i] == pre[i])
                return 1;
        }
        return 0;
    }
};