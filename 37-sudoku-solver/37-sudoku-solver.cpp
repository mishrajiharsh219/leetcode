class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>  &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isvalid(i,j,c,board)){
                        board[i][j]=c;
                      if(solve(board)==true)
                          return true;
                        else
                            board[i][j]='.';
                    }  
                }
                return false;
            }   
        }
     }
    return true;
    }
  bool isvalid(int row,int col,char c,vector<vector<char>>& board){
       for(int i=0;i<9;i++){
           if(board[row][i]==c)
               return false;
           if(board[i][col]==c)
               return false;                         //3*(row/3) or 3*(col/3) return first cell of  it;s submatrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)//for row i/3 so to move btw rows of size 3   
           return false;                          //for col i%3 to move  btw columns always 0,1,2 
       }
       return true;
   }

};


