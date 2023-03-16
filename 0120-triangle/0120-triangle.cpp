class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> next(n,0);
        for(int i=0;i<=n-1;i++)
        {
            next[i]=t[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            vector<int> curr(i+1,0);
            for(int j=i;j>=0;j--)
            {
                int down=t[i][j]+next[j];
                int dg=t[i][j]+next[j+1];
                curr[j]=min(down,dg);
            }
            next=curr;
        }
        return next[0];
    }
};