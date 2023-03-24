class Solution {
public:
    int solve(int ind1,int ind2,string &s,string &t,vector<vector<int>> &dp)
    {
        if(ind2<0)
           return ind1+1;    //t gets empty
        if(ind1<0)
            return ind2+1;      //s got empty
            
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        if(s[ind1]==t[ind2])
            return dp[ind1][ind2]=0+solve(ind1-1,ind2-1,s,t,dp);
        
        int insert=1+solve(ind1,ind2-1,s,t,dp);
        int deletion=1+solve(ind1-1,ind2,s,t,dp);
        int replace=1+solve(ind1-1,ind2-1,s,t,dp);
        return dp[ind1][ind2]=min(insert,min(deletion,replace));
    }
    int minDistance(string s, string t) {
        int m=s.length();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,s,t,dp);
    }
};