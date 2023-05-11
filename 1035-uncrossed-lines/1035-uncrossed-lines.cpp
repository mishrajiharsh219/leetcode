class Solution {
public:
    int solve(int i,int j,int m,int n,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp)
    {
     if(i==m or j==n)
         return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
    //pick
        int pick=0;
        if(nums1[i]==nums2[j])
        {
            pick=1+solve(i+1,j+1,m,n,nums1,nums2,dp);
        }
        //notpick
        int notpick=0;
        {
            notpick=max(solve(i+1,j,m,n,nums1,nums2,dp),solve(i,j+1,m,n,nums1,nums2,dp));
        }
        return dp[i][j]=max(pick,notpick);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(i,j,m,n,nums1,nums2,dp);
    }
};