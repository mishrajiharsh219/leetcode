class Solution {
public:
    void backtrack(int n,int k,vector<vector<int>> &res,vector<int> &curr,int ind){
        if(curr.size()==k)
        {
            res.push_back(curr);
        }
        for(int i=ind;i<=n;i++){
            curr.push_back(i);
            backtrack(n,k,res,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
        vector<int> curr;
        backtrack(n,k,res,curr,1);
        return res;
    }
};