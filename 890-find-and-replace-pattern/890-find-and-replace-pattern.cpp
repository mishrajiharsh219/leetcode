class Solution {
public:
    bool helper(string &s1,string &s2){
       if(s1.length()!=s2.length())
           return false;
        map<char,char> m1;
        map<char,char> m2;
        for(int i=0;i<s1.length();i++){
        m1[s1[i]]=s2[i];
        m2[s2[i]]=s1[i];
    }
       for(int i=0;i<m1.size();i++)
       {
           if((m1[s1[i]]==s2[i]) and(m2[s2[i]]==s1[i]) and (m1.size()==m2.size()))
               continue;
           else
               return false;
       }
    return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n= words.size();
        for(int i=0;i<n;i++){
            if(helper(words[i],pattern))
                res.push_back(words[i]);
        }
        return res;
    }
};