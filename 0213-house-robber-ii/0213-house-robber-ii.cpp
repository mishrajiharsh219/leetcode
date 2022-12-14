class Solution {
public:
    int dp1[101];
    int dp2[101];
     int solve2(int i,vector<int> &nums){
        
        if(i>=nums.size()){
            return 0;
        }
        if(dp2[i]!=-1)
            return dp2[i];
        
        int take=solve2(i+2,nums)+nums[i];
        int nottake=solve2(i+1,nums)+0;
        dp2[i]= max(take,nottake);
        return dp2[i];
    }
    int solve1(int i,vector<int> &nums){
        
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp1[i]!=-1)
            return dp1[i];
        
        int take=solve1(i+2,nums)+nums[i];
        int nottake=solve1(i+1,nums)+0;
        dp1[i]= max(take,nottake);
        return dp1[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int ans1= solve1(0,nums);
        int ans2=solve2(1,nums);
        return max(ans1,ans2);
    }
};