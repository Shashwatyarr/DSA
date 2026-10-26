class Solution {
public:

    long long dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0) return 0;
        vis[i][j]=1;
        return grid[i][j]+dfs(grid,vis,i,j+1)+dfs(grid,vis,i,j-1)+dfs(grid,vis,i-1,j)+dfs(grid,vis,i+1,j);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j] && !(dfs(grid,vis,i,j)%k)){
                    count++;
                }
            }
        }
        return count;
    }
};