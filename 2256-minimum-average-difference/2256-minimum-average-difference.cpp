class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
       int n=nums.size();
        vector<long long int> prefix(n,0);
        vector<long long int> suffix(n,0);
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];  
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]+nums[i];
      vector<long long int> avg(n,0);
        
        for(int i=0;i<n;i++){
        prefix[i]=abs(prefix[i]/(i+1));
        }
         for(int i=0;i<(n-1);i++){
        suffix[i]=abs(suffix[i+1]/(n-i-1));
        }
        suffix[n-1]=0;
        for(int i=0;i<n;i++)
            avg[i]=abs(prefix[i]-suffix[i]);
        
        for(auto c:avg)
            cout<<c<<" ";
       long long int minind=0;
        long long int minavg=INT_MAX;
        for(int i=0;i<n;i++){
            if(avg[i]<minavg){
            minavg=avg[i];
                minind=i;
            }
        }
            return minind;
    }
};