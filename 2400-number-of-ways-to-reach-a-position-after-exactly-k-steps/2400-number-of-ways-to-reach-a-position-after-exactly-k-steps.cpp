class Solution {
public:
    const int mod=1e9+7;
    int dp[3100][1001];
    int helper(int s,int e,int k){
        if(k==0){
            if(s==e)
                return 1;
        }
        if(k==0)
            return 0;
        if(dp[s+1000][k]!=-1)
            return dp[s+1000][k];
        
        long long ans=helper(s+1,e,k-1);
        if((e-s+1)<=(k-1))
            ans+=helper(s-1,e,k-1);
        
        return dp[s+1000][k]=ans%mod;
        
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        if(abs(endPos-startPos)>k)
            return 0;
        int ans=helper(startPos,endPos,k);
        return ans%mod;
    }
};