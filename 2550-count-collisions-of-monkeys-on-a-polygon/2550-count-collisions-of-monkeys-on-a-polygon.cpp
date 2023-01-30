class Solution {
public:
    long long int mod=1e9+7;
    long long int pow2(int n){
        if(n==1)
            return 2;
        long long int t=pow2(n/2);
        t=(t*t)%mod;
        if(n%2==0)
            return t;
        else 
            return (2*t)%mod;
    }
    int monkeyMove(int n) {
        int ans=(pow2(n)-2)%mod;
        if(ans<0)
            return mod+ans;
        return ans;
    }
};