class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] + nums[i];
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (ans[i] == ans.back() - ans[i])
                    sum += 2;
                else if (abs(ans[i] - (ans.back() - ans[i])) == 1)
                    sum++;
            }
        }
        return sum;
    }
};