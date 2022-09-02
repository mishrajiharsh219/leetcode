class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrack(res,0,0,n,str);
        return res;
    }
    void backtrack(vector<string> &res,int open,int close,int n,string str){
        if(str.size()==2*n){
            res.push_back(str);
            return;
        }
            if(open<n){
                backtrack(res,open+1,close,n,str+"(");
            }
            if(close<open){
                backtrack(res,open,close+1,n,str+")");
            }
    }
};