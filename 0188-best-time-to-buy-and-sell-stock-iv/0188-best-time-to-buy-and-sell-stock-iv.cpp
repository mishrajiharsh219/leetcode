class Solution {
public:
       int solve(int ind,int trans,vector<int> &prices,vector<vector<int>> &dp,int k)
    {
        if(ind==prices.size())
            return 0;
        if(trans==k*2)
            return 0;
        if(dp[ind][trans]!=-1)
            return dp[ind][trans];
        int profit=0;
        if(trans%2==0)
        {
      profit=max(-prices[ind]+solve(ind+1,trans+1,prices,dp,k),0+solve(ind+1,trans,prices,dp,k));
        }
        else
        {
       profit=max(prices[ind]+solve(ind+1,trans+1,prices,dp,k),0+solve(ind+1,trans,prices,dp,k));
        }
        return dp[ind][trans]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(k*2,-1));
        return solve(0,0,prices,dp,k);
    }
};