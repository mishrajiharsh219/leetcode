class Solution {
public:
    int ans=1;
    unordered_map<char,int> mp;
    void helper(char c){
        if(mp.find(c)!=mp.end()){
            ans++;
             mp.clear();
        }
         mp[c]++;
    }
    int partitionString(string s) {
        if(s=="")
            return 0;
        for(int i=0;i<s.length();i++){
            helper(s[i]);
        }
        return ans; 
    }
};