class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<=n-1;i++)
        {
            dp[n-1][i]=t[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=t[i][j]+dp[i+1][j];
                int dg=t[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,dg);
            }
        }
        return dp[0][0];
    }
};