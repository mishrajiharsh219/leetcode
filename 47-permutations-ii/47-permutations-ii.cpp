class Solution {
public:
    void backtrack(set<vector<int>> &res,vector<int> &ds,vector<int> &nums,vector<int> &freq)
    {
        if(nums.size()==ds.size()){
            res.insert(ds);
        }
        for(int i=0;i<nums.size();i++){
         if(!freq[i]){
          ds.push_back(nums[i]);
             freq[i]=1;
             backtrack(res,ds,nums,freq);
             freq[i]=0;
             ds.pop_back();
         }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        backtrack(res,ds,nums,freq);
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
};