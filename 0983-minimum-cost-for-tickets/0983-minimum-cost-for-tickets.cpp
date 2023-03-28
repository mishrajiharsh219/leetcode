class Solution {
public:
    int solve(int ind,int validity,vector<int> &days,vector<int> &costs,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(days[ind]>=validity)
                return 0;
            else
                return *min_element(costs.begin(),costs.end());
        }
         if(dp[ind][validity]!=-1)
             return dp[ind][validity];
        if(days[ind]>=validity)
            return dp[ind][validity]=solve(ind-1,validity,days,costs,dp);
        
        int case1=INT_MAX,case2=INT_MAX,case3=INT_MAX;
        
        case1=costs[0]+solve(ind-1,days[ind],days,costs,dp);
        
        case2=costs[1]+solve(ind-1,max(0,days[ind]-7+1),days,costs,dp);
        
        case3=costs[2]+solve(ind-1,max(0,days[ind]-30+1),days,costs,dp);
        
        return dp[ind][validity]=min(case1,min(case2,case3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int m=costs.size();
        // int maxvalidity=days[0]-30+1;
        vector<vector<int>> dp(n,vector<int>(367,-1));
        return solve(n-1,days[n-1]+1,days,costs,dp);
    }
};