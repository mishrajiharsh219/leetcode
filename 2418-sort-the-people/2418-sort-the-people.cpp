class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        vector<string> v;
        for(int i=0; i<heights.size(); i++){
            mp[heights[i]] = names[i];
        }
        
        for(auto i:mp){
            v.push_back(i.second);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};