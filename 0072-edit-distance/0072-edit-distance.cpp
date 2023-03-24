class Solution {
public:
    int minDistance(string s, string t) {
        
        int m=s.length();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
         for(int i=0;i<=n;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
             dp[i][j]=0+dp[i-1][j-1];
        else{
        int insert=1+dp[i][j-1];
        int deletion=1+dp[i-1][j];
        int replace=1+dp[i-1][j-1];
         dp[i][j]=min(insert,min(deletion,replace));
            }
            }
        }
        return dp[m][n];
    }
};