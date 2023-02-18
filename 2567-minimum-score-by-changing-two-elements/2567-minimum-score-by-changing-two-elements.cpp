class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=abs(nums[1]-nums[n-2]);
        int b=abs(nums[0]-nums[n-3]);
        int c=abs(nums[2]-nums[n-1]);
        return min(min(a,b),c);
    }
};