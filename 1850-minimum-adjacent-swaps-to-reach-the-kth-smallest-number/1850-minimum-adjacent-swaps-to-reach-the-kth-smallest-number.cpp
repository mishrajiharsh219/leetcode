class Solution {
public:
    int getMinSwaps(string num, int k) {
        int ans=0;
        string org=num;
        while(k--){
            next_permutation(num.begin(),num.end());
        }
        for(int i=0;i<num.size();i++){
            int ii=i+1;
            while(num[i]!=org[i]){
                ans++;
                swap(num[i],num[ii++]);
            }
        }
        return ans;
    }
};