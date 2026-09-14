class Solution {
public:
    vector<vector<int>> vis;

    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]){
            return 0;
        }
        if(grid[i][j]==0) return 0;
        vis[i][j]=1;
        return 1+dfs(i+1,j,grid)+dfs(i,j+1,grid)+dfs(i-1,j,grid)+dfs(i,j-1,grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis.resize(n,vector<int>(m,0));
        int  ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        } 
        return ans;
    }
};