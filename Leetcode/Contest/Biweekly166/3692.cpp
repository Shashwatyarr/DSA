class Solution
{
public:
    string majorityFrequencyGroup(string s)
    {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }
        unordered_map<int, string> mpp2;
        for (auto it : mpp)
        {
            mpp2[it.second] += it.first;
        }
        int size = 0;
        int k = 0;
        string maxi = "";
        for (auto it : mpp2)
        {
            int k1 = it.first;
            if (it.second.size() > size || (it.second.size() == size && k1 > k))
            {
                size = it.second.size();
                k = k1;
                maxi = it.second;
            }
        }
        return maxi;
    }
};