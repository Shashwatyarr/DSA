class Solution {
public:
    vector<vector<int>> dp;
    int find(vector<int>& nums, int idx, int sum) {
        if (sum < 0)
            return INT_MAX;
        if (sum == 0)
            return 0;
        if (idx < 0)
            return INT_MAX;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int take = INT_MAX;
        int a=nums[idx],cnt=0;
        while(a<=sum){
            int res=find(nums,idx-1,sum-a);
            if(res!=INT_MAX) take=min(cnt+res,take);
            cnt++;
            a*=2;
        }
        
        a=nums[idx],cnt=0;
        while(a){
            int res=find(nums,idx-1,sum-a);
            if(res!=INT_MAX) take=min(cnt+res,take);
            cnt++;
            a/=2;
        }
        int nottake = find(nums, idx - 1, sum);
        return dp[idx][sum] = min(take, nottake);
    }

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(sum+1, -1));
        int ans=find(nums, n - 1, sum);
        return ans==INT_MAX?-1:ans;
    }
};