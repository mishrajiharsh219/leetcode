class Solution {
public:
    bool isvowel(char t)
    {
          char c = tolower(t);
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0;
        int n=s.length();
        int j=0;
        int ans=0,curr=0;
        bool flag=true;
        while(j-i+1<=k)
        {
             if(isvowel(s[j]))
                    curr++;
            j++;
        }
         ans=max(ans,curr);
        j--;
        while(j<n and j-i+1==k)
        {
       
            if(isvowel(s[j+1]))
                curr++;
            if(isvowel(s[i]))
                curr--;
            i++;
            j++;
            ans=max(ans,curr);
            }
        return ans;
    }
};