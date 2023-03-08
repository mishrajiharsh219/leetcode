class Solution {
public:
    long long coloredCells(int n) {
     // logic=1,1+4,1+4+8 in picture so that is the pattern
    long long ans=1;
        if(n==1)
            return 1;
        for(int i=2;i<=n;i++)
        {
            ans+=4*(i-1);
        }
        return ans;
    }
};