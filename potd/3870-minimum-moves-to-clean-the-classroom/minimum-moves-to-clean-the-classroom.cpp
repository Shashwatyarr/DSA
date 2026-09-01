class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size();
        int sx,sy,k=0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S') sx=i,sy=j;
                if(classroom[i][j]=='L') id[i][j]=k++;
            }
        }
        int full=(1<<k)-1;
        vector<vector<vector<vector<bool>>>> vis(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(energy+1,vector<bool>(1<<k))));
        queue<array<int,5>> q;
        q.push({sx,sy,energy,0,0});
        vis[sx][sy][energy][0]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            auto [x,y,e,mask,moves]=q.front();
            q.pop();
            if(mask==full) return moves;
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx<0||ny<0||nx>=m||ny>=n||classroom[nx][ny]=='X') continue;
                if(e==0) continue;
                int ne=e-1,nmask=mask;
                if(classroom[nx][ny]=='L') nmask|=(1<<id[nx][ny]);
                if(classroom[nx][ny]=='R') ne=energy;
                if(vis[nx][ny][ne][nmask]) continue;
                vis[nx][ny][ne][nmask]=1;
                q.push({nx,ny,ne,nmask,moves+1});
            }
        }
        return -1;
    }
};