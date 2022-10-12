class Solution {
public:
    int gcD(int a,int b){
        if(a==0)
            return b;
        else
            return gcD(b%a,a);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=nums[0];
        int high=nums[nums.size()-1];
        int ans=gcD(low,high);
        return ans;
    }
};