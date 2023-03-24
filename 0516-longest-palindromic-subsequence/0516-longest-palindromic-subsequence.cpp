class Solution {
public:
    int solve(string &s, string &r)
    {
        int m=s.length();
        int n=r.length();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++)dp[i][0]=0;
        
        for(int j=0;j<=n;j++)dp[0][j]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==r[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size()-1;
        string r(s.begin(),s.end());
        reverse(r.begin(),r.end());
        return solve(s,r);
    }
};