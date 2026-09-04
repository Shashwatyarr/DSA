class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int count=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int j=0;j<=i;j++){
                maxi=max(maxi,nums[j]);
            }
            for(int j=i;j<nums.size();j++){
                mini=min(mini,nums[j]);
            }
            if(1LL*maxi-mini<=k*1LL){
                count=min(count,i);
            }
        }
        if(count==INT_MAX) return -1;
        return count;
    }
};