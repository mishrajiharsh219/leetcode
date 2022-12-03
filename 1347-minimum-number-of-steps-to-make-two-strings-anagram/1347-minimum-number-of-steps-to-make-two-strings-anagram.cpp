class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto c:s)
            mp1[c]++;
        for(auto c:t)
            mp2[c]++;
        for(auto c:mp1){
            if(mp2.find(c.first)!=mp2.end()){
                if(mp2[c.first]>=mp1[c.first])
                    continue;
                else
                    ans+=mp1[c.first]-mp2[c.first];
            }
            else
                ans+=mp1[c.first];
            }
        return ans;
    }
};