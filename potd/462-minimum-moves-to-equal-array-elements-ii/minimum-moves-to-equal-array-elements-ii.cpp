class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target = nums[n/2];
        int ans =0;
        for(int i: nums){
            ans+=abs(target-i);
        }
        return ans;

    }
};