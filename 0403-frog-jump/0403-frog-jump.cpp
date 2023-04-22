class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
         dp[0][1]=true;
        for(int i=1;i<n;i++)
        {
        for(int prevind=0;prevind<i;prevind++)
        {
            int dis=stones[i]-stones[prevind];
            if(dis>0 and dis<n and dp[prevind][dis])
            {
             if(i==n-1)
                 return true;
            dp[i][dis]=true;
            if(dis-1>=0) dp[i][dis-1]=true;
            if(dis+1<n) dp[i][dis+1]=true;
            }
        }
        }
        return false;
    }
};