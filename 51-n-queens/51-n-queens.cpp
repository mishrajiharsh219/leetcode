//non optimized solution of n queen

class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q')
                return false;
                row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q')
            return false;
            col--;
            }
        row=duprow;
            col=dupcol;
            while(row<=n-1 and col>=0){
                if(board[row][col]=='Q')
            return false;
            row++;
                col--;
            }
        
        return true;
    }
    void solve(int col,vector<string> &board, vector<vector<string>> &res, int n){
        if(col>=n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
            board[i][col]='Q';
                solve(col+1,board,res,n);
            board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,res,n);
        return res;
    }
};