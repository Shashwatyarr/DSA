class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            long long gc = nums[i], lc = gc, pro = 1;
            for(int j = i; j < n; j++) {
                gc = gcd(gc, 1LL * nums[j]);
                lc = lcm(lc, 1LL * nums[j]);
                pro *= nums[j];
                if(pro == gc * lc) {
                    ans = max(ans, j - i + 1);
                }
                if(pro > gc * lc) break;
            }
        }
        return ans;
    }
};