class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(366,0);
        
       int k=0;
        
        for(int i=1;i<366;i++)
        {
            dp[i]=dp[i-1];
            if(i==days[k])
            {
                dp[i]=min(costs[0]+dp[i-1],min(costs[1]+dp[max(0,i-7)],costs[2]+dp[max(0,i-30)]));
                if(k<n-1)
                k++;
            }
            
        }
        return dp[365];
    }
};