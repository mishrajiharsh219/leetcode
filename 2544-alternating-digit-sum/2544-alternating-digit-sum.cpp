class Solution {
public:
    int alternateDigitSum(int n) {
        int sign=1;
        int ans=0;
        while(n>0){
            sign=-1*sign;
            int temp=n%10;
            temp=temp*sign;
            ans+=temp;
            n=n/10;
        }
        return sign*ans;
    }
};