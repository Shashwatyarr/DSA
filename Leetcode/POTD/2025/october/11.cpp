class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        long long int start = 0, end = height.size() - 1;
        int maxa = INT_MIN;
        while (start < end)
        {
            int t = min(height[start], height[end]);
            if (t * (end - start) > maxa)
            {
                maxa = min(height[start], height[end]) * (end - start);
            }
            if (height[end] > height[start])
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return maxa;
    }
};