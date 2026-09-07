class Solution {
    vector<vector<vector<int>>> dp;
public:

    int find(vector<int>& prices,int i,int f,int t){
        if(i==prices.size() || t==0) return 0;
        if(dp[i][f][t]!=-1) return dp[i][f][t];
        if(f){
            return dp[i][f][t]=max(find(prices,i+1,!f,t)-prices[i],find(prices,i+1,f,t));
        }
        return dp[i][f][t]=max(find(prices,i+1,!f,t-1)+prices[i],find(prices,i+1,f,t));
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return find(prices,0,1,2);
    }
};