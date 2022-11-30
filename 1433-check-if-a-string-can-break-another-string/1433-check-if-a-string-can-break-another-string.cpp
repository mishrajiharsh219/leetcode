class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        if(s1==s2)
            return true;
        sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
        bool one =true;
        bool two =true;
        for(int i=0;i<s1.length();i++)
            if(s1[i]<s2[i])
                one=false;
         for(int i=0;i<s1.length();i++)
            if(s2[i]<s1[i])
                two=false;
        
        if(one or two)
            return true;
    return false;
    }
};