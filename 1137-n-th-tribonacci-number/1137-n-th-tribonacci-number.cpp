class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        int a=0,b=1,c=1;
        for(int i=0;i<(n-2);i++){
         int temp=c;
        c=a+b+c;
        a=b;
        b=temp;    
        }
        return c;
    }
};