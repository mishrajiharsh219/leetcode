class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
     int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int j=0;j<n;j++)
        {
            dp[0][j]=mat[0][j]-'0';
        }
        
        for(int i=0;i<m;i++)
        {
            dp[i][0]=mat[i][0]-'0';
        }
        
        for(int i=1;i<m;i++)
        {
         for(int j=1;j<n;j++)
         {
             if(mat[i][j]=='1')
             {
                 dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
             }
         }
        }
        int maxi=0;
         for(int i=0;i<m;i++)
        {
         for(int j=0;j<n;j++)
         {
             cout<<dp[i][j]<<" ";
             maxi=max(maxi,dp[i][j]);
         }
             cout<<endl;
         }
        return maxi*maxi;
    }
};