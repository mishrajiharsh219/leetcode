class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        //base case
        // tabulation done from m-1 ->0
        for(int j1=0;j1<n;j1++)
        {
            for(int j2=0;j2<n;j2++)
            {
                if(j1==j2)
                dp[m-1][j1][j2]=grid[m-1][j1];
                else
                dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j1=0;j1<n;j1++)
            {
                for(int j2=0;j2<n;j2++)
                {
                    int maxi=INT_MIN;
                    // for every cell 3*3 conditions
                    for(int d1=-1;d1<=1;d1++)
                    {
                        for(int d2=-1;d2<=1;d2++)
                        {
                            int ans;
                            if(j1==j2)
                                ans=grid[i][j1];
                            else
                                ans=grid[i][j1]+grid[i][j2];
                            //if out of bound
                            if(j1+d1<0 or j1+d1>=n or j2+d2<0 or j2+d2>=n)
                                ans+=INT_MIN;
                            else
                                ans+=dp[i+1][j1+d1][j2+d2];
                             maxi=max(ans,maxi);
                        }
                    }
                   dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
};