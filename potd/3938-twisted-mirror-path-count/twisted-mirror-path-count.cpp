class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!dp[i][j]) continue;
                int r=i+1,c=j,next=0;
                while(r<n && c<m && grid[r][c]==1){
                    if(next==0) {c++;next=1;}
                    else{
                        r++;
                        next=0;
                    }
                }
                if(r<n && c<m) dp[r][c]=(dp[r][c]+dp[i][j])%1000000007;
                r=i;c=j+1;next=1;
                while(r<n && c<m && grid[r][c]==1){
                    if(next==0){c++;next=1;}
                    else{
                        r++;
                        next=0;
                    }
                }
                if(r<n && c<m) dp[r][c]=(dp[r][c]+dp[i][j])%1000000007;
            }
        }
        
        return dp[n-1][m-1];
    }
};