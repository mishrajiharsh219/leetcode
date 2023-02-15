class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(auto v:points){
            x.push_back(v[0]);
        }
        sort(x.begin(),x.end());
        int ans=0;
        for(int i=0;i<x.size()-1;i++){
            ans=max(ans,abs(x[i]-x[i+1]));
        }
        return ans;
    }
};