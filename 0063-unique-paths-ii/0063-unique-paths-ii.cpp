class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
      vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==1)
                    temp[j]=0;
                else if(i==0 and j==0)
                {temp[j]=1;}
                else{
                    int left=0,up=0;
                    if(i>=1)
                        up=prev[j];
                    if(j>=1)
                        left=temp[j-1];
                    temp[j]=left+up;
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};