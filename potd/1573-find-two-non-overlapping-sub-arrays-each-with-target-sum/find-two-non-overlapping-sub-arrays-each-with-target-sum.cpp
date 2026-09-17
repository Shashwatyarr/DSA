class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;
        int n = arr.size(), ans = 2 * n;
        vector<int> dp(n, INT_MAX);
        mpp[0] = -1; int sum = 0;
        for(int i = 0; i < n; i++) {
            if(i) dp[i] = dp[i-1];
            sum += arr[i];
            int req = sum - target;
            if(mpp.find(req) != mpp.end()) {
                int index = mpp[req];
                int len = i - index;
                dp[i] = min(dp[i], len);
                if(index >= 0 && dp[index] != INT_MAX) {
                    ans = min(ans, len + dp[index]);
                }
            }
            mpp[sum] = i;
        }
        return ans == 2 * n ? -1 : ans;
    }
};