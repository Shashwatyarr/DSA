class Solution {
    inline static int dp[500][501][26];
public:
    // vector<vector<vector<int>>> dp;
    int find(vector<int>& nums,int i,int j,int k){
        if(i>=nums.size()) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int take=-1e9;
        if(j==nums.size()){
            take=1+find(nums,i+1,i,k);
        }
        else if(nums[i]!=nums[j]){
            if(k>0)
            take=1+find(nums,i+1,i,k-1);
        }
        else{
            take=1+find(nums,i+1,i,k);
        }
        int nottake=find(nums,i+1,j,k);
        return dp[i][j][k]=max(take,nottake);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        // dp.resize(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return find(nums,0,n,k);
    }
};