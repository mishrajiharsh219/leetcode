class Solution {
public:
    int solve(int ind,int buy,int capacity,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(ind==prices.size())
            return 0;
        if(capacity==0)
            return 0;
        if(dp[ind][buy][capacity]!=-1)
            return dp[ind][buy][capacity];
        int profit=0;
        if(buy){
        profit=max(-prices[ind]+solve(ind+1,0,capacity,prices,dp),0+solve(ind+1,1,capacity,prices,dp));
        }
        else
        {
     profit=max(prices[ind]+solve(ind+1,1,capacity-1,prices,dp),0+solve(ind+1,0,capacity,prices,dp));
        }
        return dp[ind][buy][capacity]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         int buy=1;// 1 means allowed to buy 0 means allowed to sell only
        int capacity=k;//given
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,buy,capacity,prices,dp);
    }
};