class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
        vector<int> ans;
        for(auto c:nums){
            mp[c]++;
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k)
                pq.pop();
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};