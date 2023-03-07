class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
       long long int lowerbound=-1,maxind=-1,minind=-1;
       long long int ans=0;
        for(long long int i=0;i<nums.size();i++)
        {
            if(nums[i]==mink)
                minind=i;
             if(nums[i]==maxk)
                maxind=i;
            else if(nums[i]<mink or nums[i]>maxk)
                lowerbound=i;
            ans+=max(0LL,min(minind,maxind)-lowerbound);
        }
        return ans;
    }
};