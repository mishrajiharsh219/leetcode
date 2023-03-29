class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(k*2+1,0));
        
        for(int i=0;i<=k*2;i++)
            dp[n][i]=0;
        
        for(int i=0;i<=n;i++)
            dp[i][k*2]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=k*2-1;trans>=0;trans--)
            {
                   int profit=0;
        if(trans%2==0)
        {
      profit=max(-prices[ind]+dp[ind+1][trans+1],0+dp[ind+1][trans]);
        }
        else
        {
       profit=max(prices[ind]+dp[ind+1][trans+1],0+dp[ind+1][trans]);
        }
        dp[ind][trans]=profit;
            }
        }
        return dp[0][0];
    }
};