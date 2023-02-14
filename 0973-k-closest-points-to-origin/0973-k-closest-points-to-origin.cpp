class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        vector<vector<int>> ans;
        for(auto c:points){
            int x=c[0];
            int y=c[1];
            cout<<(pow(x,2)+pow(y,2))<<" ";
            pq.push({sqrt((pow(x,2)+pow(y,2))),{x,y}});
        }
        while(k-- and pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};