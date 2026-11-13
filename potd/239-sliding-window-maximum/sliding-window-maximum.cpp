class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int maxVal = INT_MIN;
        for (int i = 0; i < k; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
        }
        ans.push_back(maxVal);
        for (int i = 1; i <= n - k; i++) {
            if (nums[i - 1] == maxVal) {
                maxVal = INT_MIN;
                for (int j = i; j < i + k; j++) {
                    if (nums[j] > maxVal) {
                        maxVal = nums[j];
                    }
                }
            } else {
                if (nums[i + k - 1] > maxVal) {
                    maxVal = nums[i + k - 1];
                }
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
