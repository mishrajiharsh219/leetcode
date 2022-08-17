class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> gen_codes;
        for(auto ch: words){
            string code="";
            for(auto c:ch){
                code+=morse_code[c-'a'];
            }
            gen_codes.insert(code);
        }
        return gen_codes.size();
    }
};