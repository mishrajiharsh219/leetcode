class Solution {
public:
    void backtrack( vector<vector<int>> &res,vector<int> &curr,int k,int n,int ind){
        if(n==0 and curr.size()==k){
            res.push_back(curr);
        }
        for(int i=ind;i<=9;i++){
            if(n-i<0){
                return;
            }
            n-=i;
            curr.push_back(i);
            backtrack(res,curr,k,n,i+1);
                curr.pop_back();
            n+=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res,curr,k,n,1);
        return res;
    }
};