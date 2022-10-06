class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key)==0)
            return "";
        int start=0,end=mp[key].size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(mp[key][mid].first==timestamp){
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first>timestamp)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
         return (start> 0) ? mp[key][end].second : "";   
    }
};

