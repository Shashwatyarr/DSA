class Solution {
public:
    vector<vector<int>> vis;

    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]){
            return;
        }
        if(grid[i][j]=='.') return;
        vis[i][j]=1;
        dfs(i+1,j,grid),
        dfs(i,j+1,grid),
        dfs(i-1,j,grid),
        dfs(i,j-1,grid);
    }

    int countBattleships(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis.resize(n,vector<int>(m,0));
        int  ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X' && !vis[i][j]){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        } 
        return ans;
    }
};
