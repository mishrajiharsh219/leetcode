class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=0 and j>=0 and i<=m-1 and j<=n-1 and grid[i][j]==1){
            grid[i][j]=0;
            return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
            
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int m=grid.size();
        int ans=0;
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    ans=max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};