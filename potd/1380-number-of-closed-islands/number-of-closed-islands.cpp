class Solution {
public:

    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return 0;
        if(grid[i][j]) return 1;
        grid[i][j]=1;
        return dfs(grid,i,j-1)&dfs(grid,i,j+1)&dfs(grid,i+1,j)&dfs(grid,i-1,j);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count+=dfs(grid,i,j);
                }
            }
        }    
        return count;
    }
};