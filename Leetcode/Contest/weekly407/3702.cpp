class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        int f = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                f = 1;
        }
        if (!f)
            return 0;
        int o = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            o ^= nums[i];
        }
        if (o == 0)
            return nums.size() - 1;
        else
            return nums.size();
    }
};