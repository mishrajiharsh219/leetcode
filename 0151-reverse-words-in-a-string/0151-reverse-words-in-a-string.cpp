class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,j=0,n=s.size(),lastindex=0;
        while(j<n){
            while(j<n and s[j]==' ')
                j++;
            int startindex=i;
            while(j<n and s[j]!=' '){
                s[i++]=s[j++];
                lastindex=i;
            }
            reverse(s.begin()+startindex,s.begin()+i);
            s[i++]=' ';
        }
        s.resize(lastindex);
        return s;
    }
};