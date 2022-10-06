class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,true);
        v[0]=v[1]=false;
        for(int i=2;i<=n;i++){
            if(v[i]==true){
                for(int j=2*i;j<=n;j=j+i){
                    v[j]=false;
                }
            }
        }
        int count=0;
        for(int x=2;x<n;x++){
            if(v[x]==true)
                count++;
        }
        return count;
    }
};