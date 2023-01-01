class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        set<char> setc;
        set<string> sets;
        vector<string> v;
        stringstream ss(s);
        string word;
        while(ss>>word){
            v.push_back(word);
        }
        if(pattern.length()!=v.size())
            return false;
        for(auto c:pattern){
            setc.insert(c);
        }
        for(auto c:v)
            sets.insert(c);
        if(setc.size()!=sets.size())
            return false;
        for(int i=0;i<pattern.length();i++){
        if(mp.find(pattern[i])!=mp.end())
        {
            if(mp[pattern[i]]!=v[i])
                return false;
        }
        else
         mp[pattern[i]]=v[i];
         }
       return true;
    }
};