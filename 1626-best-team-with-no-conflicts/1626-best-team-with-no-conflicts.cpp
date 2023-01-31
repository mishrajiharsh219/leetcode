class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int n=scores.size();
         vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        int best=0;
        for(int i=0;i<n;i++){
            ans[i]=v[i].second;
            for(int j=0;j<i;j++){
             if(v[i].second>=v[j].second){
                 ans[i]=max(ans[i],ans[j]+v[i].second);
             }
            }
            best=max(best,ans[i]);
        }
        return best;
    }
};