class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
       vector<int> prev(n,0);
        for(int i=0;i<n;i++)
        {
            prev[i]=g[0][i];
        }
        for(int i=1;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
                c1=g[i][j]+prev[j];
                if(j-1>=0)
                c2=g[i][j]+prev[j-1];
                if(j+1<n)
                c3=g[i][j]+prev[j+1];
                temp[j]=min(c1,min(c2,c3));
            }
            prev=temp;
        }
        int ans=INT_MAX;
       for(int i=0;i<n;i++)
       {
           ans=min(ans,prev[i]);
       }
        return ans;
    }
};