class Solution {
public:
    
     void candidate(int x , int y,vector<vector<int>> &res , vector<vector<int>> &land)
    {
        bool up   = (x - 1 < 0 or land[x - 1][y] == 0);
        bool left = (y - 1 < 0 or land[x][y - 1] == 0);
        
        bool right = (y + 1 >= land[0].size() or land[x][y + 1] == 0);
        bool down  = (x + 1 >= land.size() or land[x + 1][y] == 0);
        
        if(up and left)
            res.push_back({x , y});
        
         if(right and down)
            res.back().push_back(x) , res.back().push_back(y);
         
    }
    void dfs(vector<vector<int>> &land,vector<vector<int>> &res,int i,int j){
        
        if(i>=land.size() or j>=land[0].size() or i<0 or j<0 or land[i][j]==-1 or land[i][j]==0)
            return;
        
        land[i][j]=-1;
        
        candidate(i,j,res,land);
        
        dfs(land,res,i-1,j);
        dfs(land,res,i+1,j);
        dfs(land,res,i,j-1);
        dfs(land,res,i,j+1);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
         int n=land.size();
        int m=land[0].size();
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                 dfs(land,res,i,j);
                }
            }
        }
        return res;
    }
};