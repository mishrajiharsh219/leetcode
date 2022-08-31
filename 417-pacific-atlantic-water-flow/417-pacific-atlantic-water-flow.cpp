class Solution {
public:
    
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &visited,int i,int j){
           int n=heights.size();
           int m=heights[0].size();
        
        visited[i][j]=true;
        
        if(i-1>=0 and visited[i-1][j]!=true and heights[i-1][j]>=heights[i][j])
            dfs(heights,visited,i-1,j);
        
        if(i+1<n and visited[i+1][j]!=true and heights[i+1][j]>=heights[i][j])
        dfs(heights,visited,i+1,j);
        
        if(j+1<m and visited[i][j+1]!=true and  heights[i][j+1]>=heights[i][j])
            dfs(heights,visited,i,j+1);
        
        if(j-1>=0 and visited[i][j-1]!=true and heights[i][j-1]>=heights[i][j])
            dfs(heights,visited,i,j-1);
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
   vector<vector<int>> res;
        
        int n=heights.size();//rows
        int m=heights[0].size();//colums
        
        vector<vector<bool>> pacific(n,vector<bool>(m));
        vector<vector<bool>> atlantic(n,vector<bool>(m));
        
        
       for(int i=0;i<n;i++){
        dfs(heights,pacific,i,0);
           dfs(heights,atlantic,i,m-1);
       }
        
          for(int i=0;i<m;i++){
        dfs(heights,pacific,0,i);
           dfs(heights,atlantic,n-1,i);
       }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==true and atlantic[i][j]==true)
                    res.push_back({i,j});
            }
        }
        return res;
    }
};