class Solution {
public:
    void findcomb(vector<vector<int>> &res,int i,int target,vector<int> &candidates,vector<int> &ds){
        if(i==candidates.size()){
            if(target==0)
                res.push_back(ds);
            return;
        }
        if(candidates[i]<=target){
        target-=candidates[i];
        ds.push_back(candidates[i]);
        findcomb(res,i,target,candidates,ds);
            target+=candidates[i];
        ds.pop_back();
        }
        
        findcomb(res,i+1,target,candidates,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int i=0,k=0,n=candidates.size();
        findcomb(res,i,target,candidates,ds);
        return res;
    }
};