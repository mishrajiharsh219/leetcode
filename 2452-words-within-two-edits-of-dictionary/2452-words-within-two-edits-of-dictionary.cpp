class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        unordered_set<string> ans;
        int n=queries[0].length();
        for(int i=0;i<queries.size();i++){
            string s1=queries[i];
            for(int j=0;j<dictionary.size();j++){
                string s2=dictionary[j];
                int diff=0;
                for(int k=0;k<n;k++){
                    if(s1[k]!=s2[k])
                        diff++;
                }
                if(diff<=2){
                    ans.insert(s1);
                }
            }
        }
        vector<string> res;
        for(auto s:queries){
            if(ans.find(s)!=ans.end())
                res.push_back(s);
        }
        return res;
    }
};