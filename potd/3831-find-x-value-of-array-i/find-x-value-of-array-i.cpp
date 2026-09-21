class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<long long> dp(k);
        for (int x : nums) {
            vector<long long> temp(k);
            int rem = x % k;
            temp[rem]++;
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                temp[newRem] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += temp[r];
            }
            dp = temp;
        }
        return ans;
    }
};