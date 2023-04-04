class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(1001,0);
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        dp[3]=0;
        for(int i=4;i<=1000;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i%j==0 and dp[i-j]==0)
                    dp[i]=1;
            }
        }
        return dp[n];
    }
};