class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& stones,int i,vector<int> &vis){
        if(vis[i]==0)
            vis[i]=1;
            
            for(int j=0;j<stones.size();j++){
                if(vis[j]==0 and (stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]))
                {
                    ans++;
                    dfs(stones,j,vis);
                }
            }
    }
    int removeStones(vector<vector<int>>& stones) {
        vector<int> vis(stones.size(),0);
        
        for(int i=0;i<stones.size();i++){
            if(vis[i]==0)
                dfs(stones,i,vis);
        }
        return ans;
    }
};