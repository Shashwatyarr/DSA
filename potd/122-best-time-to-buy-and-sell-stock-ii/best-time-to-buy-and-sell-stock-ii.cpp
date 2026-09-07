class Solution {
public:
    vector<vector<int>> dp;

    int find(vector<int>& prices,int i, int f){
        if(i>=prices.size()) return 0;
        if(dp[i][f]!=-1) return dp[i][f];
        if(f){
            return dp[i][f]=max(find(prices,i+1,!f)-prices[i],find(prices,i+1,f));
        }
        return dp[i][f]=max(find(prices,i+1,!f)+prices[i],find(prices,i+1,f));
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return find(prices,0,1);
    }
};