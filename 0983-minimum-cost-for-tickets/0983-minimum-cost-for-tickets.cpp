class Solution {
public:
//     # a = cost[one day pass] + cost of next day
// # b = cost[ week pass ] + cost of next day after week
// # c = cost[ month pass ] + cost of next day after month
    int solve(int ind,vector<int> &days,vector<int> &costs,vector<int> &dp)
    {
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int case1=INT_MAX,case2=INT_MAX,case3=INT_MAX;
        
        case1=costs[0]+solve(ind-1,days,costs,dp);
        
        
        int newindex=ind;
        for(newindex=ind;newindex>=0 and days[newindex]>=(days[ind]-7+1);newindex--){}
        case2=costs[1]+solve(newindex,days,costs,dp);
        
        for(newindex=ind;newindex>=0 and days[newindex]>=(days[ind]-30+1);newindex--){}
        case3=costs[2]+solve(newindex,days,costs,dp);
        
        
        return dp[ind]=min(case1,min(case2,case3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(366,-1);
        return solve(n-1,days,costs,dp);
        
    }
};