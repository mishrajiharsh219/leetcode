class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        
        for(int i=0;i<=3;i++)
            dp[n][i]=0;
        
        for(int i=0;i<=n;i++)
            dp[i][4]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=3;trans>=0;trans--)
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