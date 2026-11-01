class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mini) count+=nums[i]-mini;
        }
        return count;
    }   
};