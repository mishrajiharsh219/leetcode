class Solution {
public:
    string diff(string s){
        string result;
      for(int i=0;i<s.length();i++){
          int cnt=1;
          while(i<s.length() and s[i]==s[i+1])
          {
              cnt++;
              i++;
          }
          result+=to_string(cnt);
          result+=s[i];
      }
        return result;
    }
    void helper(string &res,int n,int i){
        if(i==n)
            return;
        res=diff(res);
        helper(res,n,i+1);
    }
    string countAndSay(int n) {
    string res="1";
    helper(res,n,1);
        return res;
    }
};