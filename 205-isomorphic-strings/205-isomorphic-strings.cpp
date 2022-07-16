class Solution {
public:
    bool isIsomorphic(string s, string t) {
      map<char,char> mp;
        int l=s.length();
        int m=t.length();
         map<char,char> mp1;
        if(l!=m)
            return false;
        for(int i=0;i<l;i++){
            if(mp.find(s[i])!=mp.end() and mp[s[i]]!=t[i])
                return false;
            mp[s[i]]=t[i];
        }
          for(int i=0;i<l;i++){
            if(mp1.find(t[i])!=mp1.end() and mp1[t[i]]!=s[i])
                return false;
            mp1[t[i]]=s[i];
        }
        return true;
    }
};