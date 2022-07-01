class Solution {
public:
    double myPow(double x, int n) {
      long long nn=n;
        if(nn==0) return 1;
    if(x==1)return double(1);
        if(nn<0) {
        nn = -nn;
        x = 1/x;
    }
   double ans = 1;
    while(nn>0){
        if(nn&1) ans *= x;
        x *= x;
        nn >>= 1;
    }
    return ans;
    }
};