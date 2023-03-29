class Solution {
public:
    int solve(int ind,int trans,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(trans==4)
            return 0;
        if(dp[ind][trans]!=-1)
            return dp[ind][trans];
        int profit=0;
        if(trans%2==0)
        {
      profit=max(-prices[ind]+solve(ind+1,trans+1,prices,dp),0+solve(ind+1,trans,prices,dp));
        }
        else
        {
       profit=max(prices[ind]+solve(ind+1,trans+1,prices,dp),0+solve(ind+1,trans,prices,dp));
        }
        return dp[ind][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(0,0,prices,dp);
    }
};