class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i=num.size()-1;i>=0 and k;i--){
            num[i]=num[i]+k;
            k=num[i]/10;
            num[i]=num[i]%10;
        }
        while(k>0){
            num.insert(num.begin(),k%10);
            k=k/10;
        }
        return num;
    }
};