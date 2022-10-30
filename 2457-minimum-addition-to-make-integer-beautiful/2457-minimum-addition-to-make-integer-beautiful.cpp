class Solution {
public:
    long long sumofdig(long long n){
        long long temp=0;
        while(n>0){
            int t=n%10;
            temp+=t;
            n=n/10;
        }
        return temp;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if(sumofdig(n)<=target)
            return 0;
       long long int count=10;
       long long int temp=n;
       long long int mod;
        while(sumofdig(temp)>target){
            mod=n%count;
            temp=n+count-mod;
            count=count*10;
        }
        return temp-n;
    }
};