class Solution {
public:
        unordered_map<char,int> mp;
    bool isAlienSorted(vector<string>& words, string order) {
    
        for(int i=0;i<order.size();i++)
            mp[order[i]]=i;
        for(int i=0;i<(words.size()-1);i++){
       if(check(words[i],words[i+1])==false)
           return false;
        }
        return true;
    }
    bool check(string a,string b){
       if(mp[a[0]]<mp[b[0]])
           return true;
       else if(mp[a[0]]>mp[b[0]])
           return false;
        else if(a.size()>1 and b.size()>1){
            return check(a.substr(1,a.size()-1),b.substr(1,b.size()-1));
        }
        if(a.size()==1)
            return true;
        return false;
    }
};