class Solution {
public:
    int mod=1e9+7;
    int solve(int num,int oper,unordered_map<int,vector<int>> &mp,vector<vector<int>> &dp)
    {
        if(oper==0)
            return 1;
        if(dp[num][oper]!=-1)
            return dp[num][oper]%mod;
        int ways=0;
        vector<int> temp=mp[num];
        for(auto c:temp)
        {
            ways=(ways%mod)+solve(c,oper-1,mp,dp)%mod;
        }
        return dp[num][oper]=ways%mod;
    }
    int knightDialer(int n) {
        int count=n;
        unordered_map<int,vector<int>> mp;
        mp[1]={6,8};
        mp[2]={7,9};
        mp[3]={4,8};
        mp[4]={3,9,0};
        mp[6]={0,1,7};
        mp[7]={2,6};
        mp[8]={1,3};
        mp[9]={2,4};
        mp[0]={4,6};
        mp[5]={};
        vector<vector<int>> dp(10,vector<int>(n,-1));
        int ways=0;
        for(auto it:mp)
        {
            ways=(ways%mod)+solve(it.first,count-1,mp,dp)%mod;
        }
        return ways%mod;
    }
};