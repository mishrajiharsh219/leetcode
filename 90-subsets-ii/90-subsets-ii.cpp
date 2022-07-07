class Solution {
public:
    void subsum(set<vector<int>> &res,int i,int n,vector<int> &a,vector<int> &dp){
         if(i==n){
             res.insert(dp);
             return;
         }
         dp.push_back(a[i]);
         subsum(res,i+1,n,a,dp);
         dp.pop_back();
         subsum(res,i+1,n,a,dp);
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<int> dp;
       int i=0,sum=0;
      subsum(res,i,nums.size(),nums,dp);
        vector<vector<int>> res1(res.begin(),res.end());
      return res1; 
    }
};