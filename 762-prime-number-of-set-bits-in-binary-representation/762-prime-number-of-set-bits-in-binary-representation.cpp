class Solution {
public:
    int setbits(int n){
        int cnt=0;
        while(n!=0){
            if(n&1){
            cnt++;}
                n=n>>1;
            
        }
        return cnt;
    }
    bool isprime(int n){
        int fact=0;
        if(n==1)return false;
        for(int i=2;i<n;i++){
            if(n%i==0)fact++;
        }
        if(fact>0)
            return false;
        return true;
        
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        vector<int> res;
        for(int i=left;i<=right;i++){
            res.push_back(setbits(i));
            
        }
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
            if(isprime(res[i]))
                ans++;
        }
    return ans;}
};