class Solution {
public:
    long long sumofdivisor(int n){
        int divisor=2;
        long long ans=0;
        while(n>1){
            if(n%divisor==0)
            {
             n=n/divisor;
            ans+=divisor;
            }
            else
            divisor++;
        }
        return ans;
    }
    int smallestValue(int n) {
        while(true){
            long long sum=sumofdivisor(n);
            if(sum==n)
            break;
            n=sum;
        }
        return n;
    }
};