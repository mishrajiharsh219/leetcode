class Solution {
public:
    bool halvesAreAlike(string s) {
       int  cnt1=0,cnt2=0;
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
               cnt1++;
               }
               }
            for(int i=(n/2);i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
               cnt2++;
               }
               }   
       if(cnt1==cnt2)
               return true;
               return false;
    }
};