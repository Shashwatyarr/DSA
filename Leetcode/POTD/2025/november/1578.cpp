class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size(), m = neededTime.size();
        int l = 0, r = 1, sum = 0;
        while (r < m)
        {
            if (colors[l] == colors[r])
            {
                if (neededTime[l] <= neededTime[r])
                {
                    sum += neededTime[l];
                    l = r;
                    r++;
                }
                else
                {
                    sum += neededTime[r];
                    r++;
                }
            }
            else
            {
                l = r;
                r++;
            }
        }
        return sum;
    }
};