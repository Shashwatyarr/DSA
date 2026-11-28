class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = items.size(), cheapest = items[0][1];
        vector<int> nums(n + 1), factor(n + 1);
        for(auto& it : items) nums[it[0]]++;
        for(int i = 1; i <= n; i++) {
            factor[i] = nums[i] - 1;
            for(int j = 2 * i; j <= n; j += i) {
                factor[i] += nums[j];
            }
        }
        int ans = 0;
        for (auto& it : items) {
            if(!factor[it[0]]) continue;
            if(cheapest * 2 < it[1]) break;
            int cnt = min(budget / it[1], factor[it[0]]);
            ans += cnt * 2; budget -= cnt * it[1];
        }
        return ans + budget / cheapest;
    }
};