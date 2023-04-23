class Solution {
public:
    bool canCross(vector<int>& stones) {
        // index->0 to n-2
            // jump-> 1 to n-1
        int n=stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        dp[0][1]=1;
        for(int i=1;i<stones.size();i++)
        {
            for(int j=0;j<i;j++)
            {
             int dis=stones[i]-stones[j];
                if(dis<=0 or dis>=n or !dp[j][dis])
                    continue;
                if(i==n-1)
                    return true;
                dp[i][dis]=true;
                if(dis-1>=0) dp[i][dis-1]=true;
                if(dis+1<n)dp[i][dis+1]=true;
            }
        }
        return false;
    }
};