class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto x:order)
            mp1[x]++;
        for(auto x:s)
            mp2[x]++;
        
        string res="";
        for(auto x:order){
            if(mp2.find(x)!=mp2.end())
            {
                for(int i=0;i<mp2[x];i++)
                res+=x;
                mp2.erase(x);
            }
        }
        for(auto x:mp2)
            for(int i=0;i<x.second;i++)
            res+=x.first;
        return res;
    }
};