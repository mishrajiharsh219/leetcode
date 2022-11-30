class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto x:arr){
            mp[x]++;
        }
        set<int> s;
        for(auto x:mp){
            s.insert(x.second);
        }
        if(s.size()==mp.size())
            return true;
        return false;
    }
};