class Solution {
public:
    vector<vector<vector<int>>> dp;
    void find(int i,int j,int k,int n,int m,vector<vector<int>>& a){
        if(i>n-1 || j>m-1) return;
        if(dp[i][j][k]!=-1) return;
        int xo = k ^ a[i][j];
        find(i,j+1,xo,n,m,a);
        find(i+1,j,xo,n,m,a);
        dp[i][j][k]=xo;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(1500,-1)));
        find(0,0,0,n,m,grid);
        int mini=INT_MAX;
        for(int i=0;i<1500;i++){
            if(dp[n-1][m-1][i]==-1) continue;
            mini=min(mini,dp[n-1][m-1][i]);
        }
        return mini;
    }
};