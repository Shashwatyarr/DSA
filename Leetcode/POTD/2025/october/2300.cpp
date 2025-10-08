class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
        {
            int right = potions.size() - 1, left = 0, mid, count = 0;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                if ((long long)spells[i] * potions[mid] >= success)
                {
                    count = potions.size() - mid;
                    right = mid - 1;
                }
                else if ((long long)spells[i] * potions[mid] < success)
                {
                    left = mid + 1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};