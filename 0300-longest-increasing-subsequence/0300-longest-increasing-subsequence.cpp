class Solution {
public:
    int solve(int ind,int prev_index,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind][prev_index+1]!=-1)
            return dp[ind][prev_index+1];
        int take=0,notake=0;
        if(prev_index==-1 or nums[ind]>nums[prev_index])
        {
            take=1+solve(ind+1,ind,nums,dp);
        }
        notake=0+solve(ind+1,prev_index,nums,dp);
        
        return dp[ind][prev_index+1]=max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev_index=-1;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,prev_index,nums,dp);
    }
};