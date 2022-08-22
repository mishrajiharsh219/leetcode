class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
       long long int n=shifts.size();
        for(int i=shifts.size()-2;i>=0;i--){
            shifts[i]+=shifts[i+1];
            shifts[i]=shifts[i]%26;
        }
      
          for(int i=0;i<shifts.size();i++){
           shifts[i]=shifts[i]%26;
        }
         for(int i=0;i<n;i++){
           s[i]=((s[i] - 'a') + shifts[i]) % 26 + 'a';
         }
        return s;
    }
};