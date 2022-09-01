class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
          int n=board.size();
        int m=board[0].size();
        
        if(i<0 or i>=n or j<0 or j>=m){
            return;
        }
        if(board[i][j]=='.')
            return;
        
        board[i][j]='.';
        
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int ships=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X')
                {   ships++;
                dfs(board,i,j);}
            }
        }
        return ships;
    }
};