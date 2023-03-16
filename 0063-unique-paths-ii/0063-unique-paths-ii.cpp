class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1)
                    dp[i][j]=0;
                else if(i==0 and j==0)
                    continue;
                else{
                    int left=0,up=0;
                    if(i>=1)
                        up=dp[i-1][j];
                    if(j>=1)
                        left=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};