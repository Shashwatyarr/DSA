class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;
        int maxi = 0;
        for (auto it : mpp)
        {
            maxi = max(it.second, maxi);
        }
        int sum = 0;
        for (auto it : mpp)
        {
            if (it.second == maxi)
                sum += maxi;
        }
        return sum;
    }
};