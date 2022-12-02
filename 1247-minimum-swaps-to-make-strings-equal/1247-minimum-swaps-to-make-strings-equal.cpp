class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n!=m)
            return -1;
        
        int xmiss=0,ymiss=0;
        
        for(int i=0;i<n;i++){
            if(s1[i]=='x' and s1[i]!=s2[i])
                xmiss++;
            if(s1[i]=='y' and s1[i]!=s2[i])
                ymiss++;
        }
        
        if(xmiss%2!=ymiss%2)
            return -1;
        
        int ans=0;
        ans+=xmiss/2+ymiss/2;
        if(xmiss%2!=0)
            ans+=2;
        
        return ans;
    }
};