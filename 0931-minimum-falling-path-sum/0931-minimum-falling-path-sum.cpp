class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=g[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
                c1=g[i][j]+dp[i-1][j];
                if(j-1>=0)
                c2=g[i][j]+dp[i-1][j-1];
                if(j+1<n)
                c3=g[i][j]+dp[i-1][j+1];
                dp[i][j]=min(c1,min(c2,c3));
            }
        }
        int ans=INT_MAX;
       for(int i=0;i<n;i++)
       {
           ans=min(ans,dp[m-1][i]);
       }
        return ans;
    }
};