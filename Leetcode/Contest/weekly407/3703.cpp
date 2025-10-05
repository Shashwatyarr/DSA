class Solution
{
public:
    string removeSubstring(string s, int k)
    {
        if (k == 0)
            return s;
        string t = "";
        int a = k;
        while (a--)
        {
            t += "(";
        }
        a = k;
        while (a--)
        {
            t += ")";
        }
        string ans = "";
        int ts = k * 2;
        for (int i = 0; i < s.size(); i++)
        {
            ans += s[i];
            if (ans.size() >= ts)
            {
                if (ans.compare(ans.size() - ts, ts, t) == 0)
                {
                    ans.resize(ans.size() - ts);
                }
            }
        }
        return ans;
    }
};