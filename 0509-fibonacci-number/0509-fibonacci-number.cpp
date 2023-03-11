class Solution {
public:
    int fib(int n) {
        int prev=1;
        int prev2=0;
         int curr=0;
        if(n<=1)
            return n;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};