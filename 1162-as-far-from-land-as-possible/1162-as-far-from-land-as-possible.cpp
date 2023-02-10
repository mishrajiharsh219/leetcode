class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int distance=-1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited=grid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.size()==0 or q.size()==n*m)
            return -1;
        
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
         int size=q.size();
            while(size--){
                auto d=q.front();
                q.pop();
                for(auto c:dir){
                    int i=d.first+c.first;
                    int j=d.second+c.second;
                    if(i>=0 and i<n and j>=0 and j<m and visited[i][j]!=1){
                        visited[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};