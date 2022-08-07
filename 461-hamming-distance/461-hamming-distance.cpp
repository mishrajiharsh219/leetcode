class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x>0 or y>0){
            int a=x&1;
            int b=y&1;
            if(a!=b)
                ans++;
           x/=2;
            y/=2;
        }
        return ans;
    }
};