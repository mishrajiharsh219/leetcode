class Solution {
public:
    string reverseVowels(string s) {
        string vowel;
        for(auto c: s){
            if(c=='A' or c=='a' or c=='E' or c=='e' or c=='i' or c=='I' or c=='o' or c=='O' or c=='u' or c=='U')
            vowel.push_back(c);
        }
        reverse(vowel.begin(),vowel.end());
        cout<<vowel;
        for(int i=0;i<s.length();i++){
             if(s[i]=='A' or s[i]=='a' or s[i]=='E' or s[i]=='e' or s[i]=='i' or s[i]=='I' or s[i]=='o' or s[i]=='O' or s[i]=='u' or s[i]=='U')
             {
                 s[i]=vowel[0];
                 vowel=vowel.erase(0,1);
             }
        }
        return s;
    }
};