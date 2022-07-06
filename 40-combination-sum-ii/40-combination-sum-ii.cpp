class Solution {
public:
    void findcomb(vector<vector<int>> &res,int ind,int target,vector<int> &candidates,vector<int> &ds){
         if(target==0){
         res.push_back(ds);
            return;
         }
        
        for(int i=ind;i<candidates.size();i++){
         if(i>ind and candidates[i]==candidates[i-1])
             continue;
            if(target<candidates[i])
                break;
            ds.push_back(candidates[i]);
            target-=candidates[i];
            findcomb(res,i+1,target,candidates,ds);
            ds.pop_back();
            target+=candidates[i];
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        int i=0;
        findcomb(res,i,target,candidates,ds);
        return res;
    }
};