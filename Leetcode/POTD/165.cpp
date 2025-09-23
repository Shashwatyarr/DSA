class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int l = 0, r = 0;
        int n = version1.size(), m = version2.size();
        while (l < version1.size() || r < version2.size())
        {
            long long n1 = 0, n2 = 0;
            while (l < version1.size() && version1[l] != '.')
            {
                n1 += n1 * 10 + version1[l++] - '0';
            }
            while (r < version2.size() && version2[r] != '.')
            {
                n2 += n2 * 10 + version2[r++] - '0';
            }
            if (n1 < n2)
                return -1;
            if (n1 > n2)
                return 1;
            if (version1[l] == '.')
                l++;
            if (version2[r] == '.')
                r++;
        }
        return 0;
    }
};