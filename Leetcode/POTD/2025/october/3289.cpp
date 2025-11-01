class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        vector<int> a;
        for (auto it : nums)
        {
            if (mpp.find(it) != mpp.end())
                a.push_back(it);
            mpp[it]++;
        }
        return a;
    }
};