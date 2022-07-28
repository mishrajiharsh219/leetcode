class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int n=s.length(),m=t.length();
        while(i<n and j<m){
            if(s[i]==t[j]){
                i++;j++;
            }
            else
                j++;
        }
        if(i==n)
            return true;
        else
            return false;
    }
};