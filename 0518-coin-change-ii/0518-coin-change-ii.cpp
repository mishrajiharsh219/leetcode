class Solution {
public:
    int solve(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp)
    {
        if(amount==0)
            return 1;
        if(ind==0)
        {
            if(amount%coins[ind]==0)
                return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int take=0,notake=0;
        if(coins[ind]<=amount)
            take=solve(ind,amount-coins[ind],coins,dp);
        notake=solve(ind-1,amount,coins,dp);
        return dp[ind][amount]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);  
    }
};