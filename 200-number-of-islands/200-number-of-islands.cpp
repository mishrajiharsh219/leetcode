//dfs solution 
//connection btw the peices of land is in horizontal or vertical directions only not diagonal
//o represent water
//1 represent land
//2 represent visited visited land
//in worst case we are traversing a cell 5 time 1 time in loop and 4 times in adjacent to 4 cells
class Solution {
public:
    void markasvisited(vector<vector<char>> &grid,int i,int j,int r,int c){
        if(i<0 or j<0 or i>=r or j>=c or grid[i][j]!='1')
            return;
        
        grid[i][j]='2';//visited island
        
        markasvisited(grid,i+1,j,r,c);
        markasvisited(grid,i,j+1,r,c);
        markasvisited(grid,i-1,j,r,c);
        markasvisited(grid,i,j-1,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                {     markasvisited(grid,i,j,n,m);
                island++;}
            }
        }
        return island;
    }
};