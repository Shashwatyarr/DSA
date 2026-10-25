class Solution {
public:

    bool dfs(vector<vector<char>>& board,string word,int i,int j,int idx){
        if(idx==word.size()) return 1;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx]) return 0;
        char c=board[i][j];
        board[i][j]='#';
        bool f=dfs(board,word,i,j+1,idx+1)||dfs(board,word,i,j-1,idx+1)||dfs(board,word,i-1,j,idx+1)||dfs(board,word,i+1,j,idx+1);
        board[i][j]=c;
        return f;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0)){
                    return 1;
                }
            }
        }
        return 0;
    }
};