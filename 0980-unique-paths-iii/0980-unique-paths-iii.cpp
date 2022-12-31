class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid, int totalsteps,int currentsteps){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==-1){
            return 0;
        }
        
        if(grid[i][j]==2)
        { if(totalsteps==currentsteps)
            return 1;
         else
             return 0;
        }
        
        grid[i][j]=-1;
        
        int path=dfs(i+1,j,grid,totalsteps,currentsteps+1) + dfs(i,j+1,grid,totalsteps,currentsteps+1) + dfs(i-1,j,grid,totalsteps,currentsteps+1) + dfs(i,j-1,grid,totalsteps,currentsteps+1);
        
        grid[i][j]=0;
        
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_i=0,start_j=0;
        int totalsteps=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
              if(grid[i][j]==1)
              {start_i=i,start_j=j;}
                
                if(grid[i][j]!=-1){
                totalsteps++;
                }
            }
        }
        return dfs(start_i,start_j,grid,totalsteps,1);
    }
};