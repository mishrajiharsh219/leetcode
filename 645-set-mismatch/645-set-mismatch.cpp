class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int dup=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
           if(nums[i]==nums[i+1])
               dup=nums[i];
       }
        vector<int> res1;
        int res=0;
        for(int i=0;i<nums.size();i++){
            res=res^(i+1);
            res=res^nums[i];
        }
        res^=dup;
        return {dup,res};
    }
};