class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size();
        int n=score[0].size();
        vector<vector<int>> ans;
        vector<pair<int,int>> v;
        for(int i=0;i<m;i++){
            v.push_back({score[i][k],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
       
        for(auto c:v){
          int temp=c.second;
        ans.push_back(score[temp]);
          }
        return ans;
    }
};