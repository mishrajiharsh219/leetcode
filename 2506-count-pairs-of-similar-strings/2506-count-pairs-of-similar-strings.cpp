class Solution {
public:
    int similarPairs(vector<string>& words) {
      vector<set<char>> v;
        map<string,int> mp;
        int ans=0;
        for(auto c:words){
        set<char> temp;
            for(auto s:c)
                temp.insert(s);
            v.push_back(temp);
        }
        int i=0;
        for(auto c:v){
            string temp="";
            for(auto s:c)
            {
                
                temp+=s;
            }
            words[i++]=temp;
        }
        for(auto c:words){
            mp[c]++;
        }
        for(auto c:mp){
            if(c.second>=2){
                ans+=(c.second*(c.second-1))/2;
            }
        }
        return ans;
        }
};