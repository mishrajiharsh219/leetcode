class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            else
                dp[0][i]=INT_MAX;
        }
        
        for(int i=1;i<n;i++)
        {
        for(int j=0;j<=amount;j++)
        {
             long long nottake=INT_MAX,take=INT_MAX;
         nottake=0+dp[i-1][j];
        if(coins[i]<=j)
        take=1+dp[i][j-coins[i]];
        
         dp[i][j]=min(take,nottake);
        }
        }
        if(dp[n-1][amount]==INT_MAX)
            return -1;
        return dp[n-1][amount];
    }
};