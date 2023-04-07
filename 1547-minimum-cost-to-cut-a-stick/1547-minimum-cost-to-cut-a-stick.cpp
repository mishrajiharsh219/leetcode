class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int orgc=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(orgc+2,vector<int> (orgc+2,0));
        
        for(int i=orgc;i>=1;i--)
        {
            for(int j=1;j<=orgc;j++)
            {
                if(i>j)
                    continue;
                 int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
            mini=min(ans,mini);
        }
        dp[i][j]=mini;
            }
        }
        
        return dp[1][orgc];
    }
};