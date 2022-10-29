class Solution {
public:
    static bool cmp(pair<int,int> &p1,pair<int,int> &p2){
            return p1.second>p2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int ,int>> flow;
        for(int i=0;i<plantTime.size();i++){
            flow.push_back({plantTime[i],growTime[i]});
        }
        sort(flow.begin(),flow.end(),cmp);
        
        int ans=0;
        int start=0;
        
        for(int i=0;i<plantTime.size();i++){
        start+=flow[i].first;
        ans=max(ans,start+flow[i].second);    
        }
        return ans;
    }
};