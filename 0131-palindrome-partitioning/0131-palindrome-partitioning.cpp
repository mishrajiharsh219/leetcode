class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,path,res,s);
        return res;
    }
    void solve(int ind,vector<string> &path,vector<vector<string>> &res,string s){
        if(ind==s.length()){
            res.push_back(path);return;}
    
        for(int i=ind;i<s.length();i++){
            if(ispalindrome(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                solve(i+1,path,res,s);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
        if(s[start++]!=s[end--])
            return false;
        }
            return true;
    }
};