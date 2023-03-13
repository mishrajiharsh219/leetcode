class Solution {
public:
    int solve(vector<int> cost,int n,vector<int> &dp)
    {  
        if(n<2)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int fs=INT_MAX,ss=INT_MAX;
        fs=cost[n-1]+solve(cost,n-1,dp);
        if(n>1)
        ss=cost[n-2]+solve(cost,n-2,dp);
        dp[n]= min(fs,ss);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
     int n=cost.size();
    vector<int> dp(n+1,-1);
    int ans=solve(cost,n,dp);
        return ans;
    }
};