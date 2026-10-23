class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s=accumulate(nums.begin(),nums.end(),0);
        return s%k;
    }
};