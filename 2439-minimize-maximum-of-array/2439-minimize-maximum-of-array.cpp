class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long res=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
           long long temp=(sum+i)/(i+1);  //ceil(sum/i+1)
            res=max(res,temp);
        }
        return int(res);
    }
};