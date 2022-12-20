class Solution {
public:
      vector<bool> visited;
    void dfs(vector<vector<int>> rooms,int i){
        for(auto x:rooms[i]){
            if(visited[x]==false){
                visited[x]=true;
                dfs(rooms,x);
            }
        }
    }
  
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.resize(rooms.size());
        visited[0]=true;
        dfs(rooms,0);
        for(auto x:visited)
        {
            // cout<<x<<" ";
            if(x==false)
                return false;
        }
        return true;
    }
};