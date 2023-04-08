class Solution {
public:
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(i>j)
         return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++)
        {
        int ans=nums[j+1]*nums[i-1]*nums[ind]+solve(i,ind-1,nums,dp)+solve(ind+1,j,nums,dp);
            maxi=max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int org=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(org+1,vector<int>(org+1,-1));
        return solve(1,n-2,nums,dp);
    }
};