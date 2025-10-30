class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int t = target[0];
        for (int i = 0; i < target.size() - 1; i++)
        {
            t += max(target[i + 1] - target[i], 0);
        }
        return t;
    }
};