class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        vector<int> ans(nums.size() - 1);
        while (nums.size() > 1)
        {
            int i = 1;
            while (i < nums.size())
            {
                ans[i - 1] = (nums[i - 1] + nums[i]) % 10;
                i++;
            }
            nums.clear();
            nums.assign(ans.begin(), ans.end());
            ans.clear();
            ans.resize(nums.size() - 1);
        }
        return nums[0];
    }
};