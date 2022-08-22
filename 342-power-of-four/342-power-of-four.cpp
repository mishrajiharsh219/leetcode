class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0 and (n&(n-1))==0 and (n & 0xAAAAAAAA)==0)
            return true;
        else
        return false;
    }
};