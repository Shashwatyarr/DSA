class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<string> board;
    bool isS(int row,int col){
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return 0;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--){
            if(board[i][j]=='Q') return 0;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return 0;
        }
        return 1;
     }

    void solve(int row){
        if(row==n) {
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isS(row,i)){
                board[row][i]='Q';
                solve(row+1);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int a) {
        n=a;
        board.assign(n,string(n,'.'));
        solve(0);
        return ans;
    }
};