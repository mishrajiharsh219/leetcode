class Solution {
public:
    int minOperations(int n) {
        
       if(n==pow(2,(int)log2(n)))
           return 1;
        
        int loworequalpow2=pow(2,(int)log2(n));
        int highpow2=pow(2,(int)log2(n)+1);
        
        int bysubtract=n-loworequalpow2;
        int byadd=highpow2-n;
        
        int recur1=minOperations(bysubtract);
        int recur2=minOperations(byadd);
        
        return 1+min(recur1,recur2);
    }
};