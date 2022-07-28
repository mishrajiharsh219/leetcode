class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.length()!=t.length())
        return false;
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto count: mp){
            if(count.second)
                return false;
        }
        return true;
    }
};