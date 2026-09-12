class Solution {
public:
    vector<vector<int>> dp;
    int find(vector<int>& nums,int i,int j){
        if(i>=nums.size()) return 0;
        if(dp[i][j]!=1) return dp[i][j];
        int take=0, nottake=0;
        if(j==nums.size() || nums[i]>nums[j])
        take=1+find(nums,i+1,i);
        nottake=find(nums,i+1,j);
        return dp[i][j]=max(take,nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n+1,1));
        return find(nums,0,n);
    }
};