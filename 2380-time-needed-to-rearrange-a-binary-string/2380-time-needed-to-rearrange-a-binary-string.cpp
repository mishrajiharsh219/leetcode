class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
       int n=s.length();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(s[i]=='0' and s[i+1]=='1')
            flag=false;
        }
        
        if(flag==true)
            return 0;
        
        
        int res=0;
     x:
        int i=0;
        while(i<n-1){
           if(s[i]=='0' and s[i+1]=='1'){
               s[i]='1';
               s[i+1]='0';
               i+=2;
           } 
            else
                i++;
        }
        res++;
       for(int i=0;i<n;i++)
           if(s[i]=='0' and s[i+1]=='1')
               goto x;
        
        return res;
    }
};