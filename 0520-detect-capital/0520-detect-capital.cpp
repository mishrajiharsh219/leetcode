class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital=0,small=0;
        bool first=false;
        if(word[0]>=65 and word[0]<=90)
            first=true;
        for(int i=0;i<word.length();i++){
            if(word[i]>=65 and word[i]<=90)
                capital++;
            if(word[i]>=97 and word[i]<=122)
                small++;
        }
        if(capital==0)
            return true;
        if(small==0)
            return true;
        if(capital==1 and first==true)
            return true;
        return false;
    }
};