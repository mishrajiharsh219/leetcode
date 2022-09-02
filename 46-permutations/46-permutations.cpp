class Solution {
public:
    void perm(int ind,vector<int> &nums,vector<vector<int>> &res,vector<int> &freq,vector<int> &ds){
        if(ds.size()==nums.size())
        {
            res.push_back(ds);
            return ;
        }
            for(int i=0;i<nums.size();i++){
                if(!freq[i]){
                    ds.push_back(nums[i]);
                     freq[i]=1;
                perm(i,nums,res,freq,ds);
                freq[i]=0;
                ds.pop_back();
            }
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        vector<vector<int>> res;
        vector<int> ds;
        perm(0,nums,res,freq,ds);
        return res;
    }
};