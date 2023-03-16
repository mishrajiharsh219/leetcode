class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& t,vector<vector<int>>& dp)
    {
        if(i==0 and j==0)
            return t[0][0];
        if(i<0 or j<0)
            return INT_MAX;
        if(j>i)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        
            int one=solve(i-1,j,t,dp);
            int two=solve(i-1,j-1,t,dp);
            ans=min(one,two);
        
         dp[i][j]=ans+t[i][j];
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& t) {
      int m=t.size();
      int ans=INT_MAX;
      vector<vector<int>> dp(m,vector<int>(m,-1));  
      for(int i=0;i<m;i++)
      {
          ans=min(ans,solve(m-1,i,t,dp));
      }
        return ans;  
    }
};