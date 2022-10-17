class Solution {
public:
    bool checkIfPangram(string sentence) {
       vector<int> hash(26,0);
        if(sentence.length()<26){
            return false;
        }
        for(int i=0;i<sentence.length();i++){
            hash[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]==0)
                return false;
        }
        return true;
    }
};