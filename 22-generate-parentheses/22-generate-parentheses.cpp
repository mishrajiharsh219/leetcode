 /* The main idea here is:
        1.  In order to generate valid combinations of parentheses, we need to make sure that
            there is a closing parentheses for every open parentheses. This can be achieved by
            taking care of the following points:
            a.  At any point, no. of open parentheses > no. of closing parentheses
            b.  If no. of open parentheses == no. of closing parentheses, we have obtained a valid pattern
                (this will be our terminating condition for recursion)
            
        2.  We can repeat the process in point 1, until we have obatained all the possible combinations.
        
        */
        
        /*if no. of open and closing parentheses is equal to n, add the  
        combination to the list and return (and thus end the recursion)*/
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