class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0, ans = 0, n = nums.size();
        while(r < n) {
            mp[nums[r]]++;
            while(l < n && mp[nums[r]] > k) mp[nums[l++]]--;
            ans = max(ans, ++r - l);
        }
        return ans;
    }
};