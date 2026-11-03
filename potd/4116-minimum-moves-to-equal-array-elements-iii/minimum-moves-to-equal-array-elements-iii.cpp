class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=max-nums[i];
        }
        return sum;
    }
};