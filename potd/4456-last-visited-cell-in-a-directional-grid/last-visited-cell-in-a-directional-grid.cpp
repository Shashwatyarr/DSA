class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        vector<int> prev={0,0};
        while(true){
            if(grid[prev[0]][prev[1]]=='R' && prev[1]<m-1 && !vis[prev[0]][prev[1]+1]){
                prev[1]=prev[1]+1;
                vis[prev[0]][prev[1]]=1;
            }
            else if(grid[prev[0]][prev[1]]=='L' && prev[1]>0 && !vis[prev[0]][prev[1]-1]){
                prev[1]=prev[1]-1;
                vis[prev[0]][prev[1]]=1;
            }
            else if(grid[prev[0]][prev[1]]=='U' && prev[0]>0 && !vis[prev[0]-1][prev[1]]){
                prev[0]=prev[0]-1;
                vis[prev[0]][prev[1]]=1;
            }
            else if(grid[prev[0]][prev[1]]=='D' && prev[0]<n-1 && !vis[prev[0]+1][prev[1]]){
                prev[0]=prev[0]+1;
                vis[prev[0]][prev[1]]=1;
            }
            else return prev;
        }
        return prev;
    }
};