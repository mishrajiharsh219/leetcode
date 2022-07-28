class Solution {
public:
    string getHint(string secret, string guess) {
        int cow=0,bull=0;
        vector<int> secret1(10,0);//only can have ffrom 0 to 9
            vector<int> guess1(10,0);
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i])
              bull++;
            else{
            secret1[secret[i]-'0']++;
            guess1[guess[i]-'0']++;
            }
        }
            for(int i=0;i<secret1.size();i++){
                cow+=min(secret1[i],guess1[i]);
            }
    return to_string(bull)+"A"+to_string(cow)+"B";
    }
};