class Solution {
public:
    int solve(int i,int prev,vector<vector<int>> &pairs,vector<vector<int>> &dp)
    {
        if(i==pairs.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int pick=0;
        int notpick=0;
        if(prev==-1 or pairs[i][0]>pairs[prev][1])
        {
            pick=1+solve(i+1,i,pairs,dp);
        }
        notpick=solve(i+1,prev,pairs,dp);
        return dp[i][prev+1]=max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        if(n==1)
            return 1;
        int prev=-1;
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return solve(0,prev,pairs,dp);
    }
};