class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,vector<pair<int,int>> &mp,int men,int profit,int minprofit,vector<vector<vector<int>>> &dp)
    {
        if(ind<0)
        {
            if(men>=0 and profit>=minprofit)
                return 1;
            return 0;
        }
        if(dp[ind][men][profit]!=-1)
            return dp[ind][men][profit];
        int take=0,notake=0;
        notake=solve(ind-1,mp,men,profit,minprofit,dp)%mod;
        if(men-mp[ind].first>=0)
        take=solve(ind-1,mp,men-mp[ind].first,min(minprofit,profit+mp[ind].second),minprofit,dp)%mod;
        return dp[ind][men][profit]=((take)%mod+(notake)%mod)%mod;
    }
    int profitableSchemes(int men, int minprofit, vector<int>& group, vector<int>& profit) {
        vector<pair<int,int>> mp;
        int totalprofit=0;
        for(int i=0;i<group.size();i++)
        {
        mp.push_back({group[i],profit[i]});
            totalprofit+=profit[i];
        }
        int n=mp.size();
        vector<vector<vector<int>>> dp(102,vector<vector<int>>(102,vector<int>(102,-1)));
        return solve(n-1,mp,men,0,minprofit,dp)%mod;
    }
};