class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       unordered_map<string,int> mp;
        vector<string> res={};
            int n=s.size();
        if(n<11)
            return res;
        int l=0;int ;
        while(l<n){
            string r = s.substr(l,10);
            if(r.size()==10)
            {
              mp[r]++;
                if(mp[r]==2)res.push_back(r);
            }
            l++;
        }
        return res;
    }
};