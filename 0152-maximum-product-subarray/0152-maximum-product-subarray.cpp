class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmax=1,curmin=1;
        for(int i=0;i<nums.size();i++)
        {
            int tempmax=curmax*nums[i];
            int tempmin=curmin*nums[i];
            curmax=max(tempmax,max(tempmin,nums[i]));
            curmin=min(tempmax,min(tempmin,nums[i]));
            res=max(res,curmax);
        }
        return res;
    }
};