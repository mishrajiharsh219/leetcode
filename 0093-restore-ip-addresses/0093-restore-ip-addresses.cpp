class Solution {
public:
    vector<string> ans;
    bool isvalid(string s){
     if(s.size()>3 or s.size()==0)
         return false;
    else if(s.size()>1 and s[0]=='0')
        return false;
    else if(s.size()!=0 and stoi(s)>255)
        return false;
    return true;
    }
void solve(int i,int dot,string temp,string s){
    if(dot==3){
         if(isvalid(s.substr(i)))
         {
             ans.push_back(temp+s.substr(i));
         }
        return;
    }    
    for(int j=i;j<s.size();j++){
    
    if(isvalid(s.substr(i,j-i+1)))
    {
     temp+=s[j];
        temp.push_back('.');
        solve(j+1,dot+1,temp,s);
        temp.pop_back();
    }
    }
    return;
}
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4)
            return ans;
    string temp="";
    solve(0,0,temp,s);
        return ans;
    }
};