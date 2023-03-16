class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &g,vector<vector<int>> &dp)
    {
         if(i>=0 and j>=0 and g[i][j]==1)
             return 0;
        if(i==0 and j==0)
            return 1;
        if(i<0 or j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left=0,up=0;
        left=solve(i-1,j,g,dp);
        up=solve(i,j-1,g,dp);
        return dp[i][j]=up+left;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,g,dp);
    }
};