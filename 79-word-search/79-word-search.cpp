class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,int i,int j){
        if(word.size()==0)
            return true;
          if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j]!=word[0])
              return false;
        
        char c=board[i][j];
        board[i][j]='.';
        string s=word.substr(1);
       bool ret=(dfs(board,s,i+1,j) or dfs(board,s,i-1,j) or dfs(board,s,i,j-1) or dfs(board,s,i,j+1));
        board[i][j]=c;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(dfs(board,word,i,j))
                return true;
        }
    }
        return false;
    }
};

















