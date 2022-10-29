class Solution {
public:
    string oddString(vector<string>& words) {
        vector<vector<int>> res;
        int n=words[0].length();
        for(int i=0;i<words.size();i++){
             vector<int> temp;
            for(int j=0;j<n-1;j++){
                int a=int(words[i][j]);
                int b=int(words[i][j+1]);
                int c=b-a;
                temp.push_back(c);
            }
            res.push_back(temp);
        }
        map<vector<int>,int> mp;
        for(auto l:res){
            mp[l]++;
        }
        vector<int> temp2;
        for(auto l:res){
            if(mp[l]==1){
               for(auto r:l){
                   temp2.push_back(r);
               }
            }
        }
        for(int l=0;l<res.size();l++){
            if(res[l]==temp2){
                return words[l];
            }
        }
        return "";
    }
};