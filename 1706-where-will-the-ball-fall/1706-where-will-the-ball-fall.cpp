class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(i>=grid.size())
            return j;
        if(grid[i][j]==1 and (j+1)<grid[0].size() and grid[i][j+1]==1)
            return dfs(grid,i+1,j+1);
         if(grid[i][j]==-1 and j-1>=0 and grid[i][j-1]==-1) 
            return dfs(grid,i+1,j-1);
        if(j+1>=grid[0].size() or j-1<0)
            return -1;
        else
            return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans(m);
        for(int  i=0;i<m;i++){
            ans[i]=dfs(grid,0,i);
        }
        return ans;
    }
};