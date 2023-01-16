class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> ans(n,vector<int>(n+1,0));
        for(int i=0;i<q.size();i++){
            int r1=q[i][0];
            int c1=q[i][1];
            int r2=q[i][2];
            int c2=q[i][3];
            for(int k=r1;k<=r2;k++){
            ans[k][c1]++;
            ans[k][c2+1]--;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(j>0)
                    ans[i][j] = ans[i][j]+ans[i][j-1];
            }
        }
        
        for(int i = 0; i<n; i++){
            ans[i].pop_back();
        }
        return ans;
    }
};