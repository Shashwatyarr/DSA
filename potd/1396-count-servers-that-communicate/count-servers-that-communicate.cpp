class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int sum=0,count=0,sr=0,cr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        vector<int> sumr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sr+=grid[i][j];
            }
            sumr.push_back(sr);
            sr=0;
        }
        vector<int> colr;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                cr+=grid[j][i];
            }
            colr.push_back(cr);
            cr=0;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 &&(sumr[i]==1 && colr[j]==1))count++;
            }
        }
        return sum-count;
    }
};