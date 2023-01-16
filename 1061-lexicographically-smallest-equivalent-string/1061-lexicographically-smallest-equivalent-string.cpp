class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
      char map[26];
        for(int i=0;i<26;i++){
            map[i]=char('a'+i);
        }
        // for(int i=0;i<26;i++){
        //     cout<<map[i];
        // }
        for(int i=0;i<s1.length();i++){
            char tobereplace=max(map[s1[i]-'a'],map[s2[i]-'a']);
            char replacedby=min(map[s1[i]-'a'],map[s2[i]-'a']);
            
            for(int i=0;i<26;i++){
                if(map[i]==tobereplace)
                    map[i]=replacedby;
            }
        }
        
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=map[baseStr[i]-'a'];
        }
        return baseStr;
    }
};