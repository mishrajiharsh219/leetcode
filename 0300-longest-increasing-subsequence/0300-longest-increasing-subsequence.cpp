class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int lastindex=0;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] and 1+dp[prev]> dp[i])
                {
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
             if(dp[i]>maxi)
             {
              maxi=dp[i];
             lastindex=i;
             }
        }
        vector<int> lis;
        lis.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex)
        {
            lastindex=hash[lastindex];
            lis.push_back(nums[lastindex]);
        }
        reverse(lis.begin(),lis.end());
        for(auto c:lis)
            cout<<c<<" ";
        return maxi;
    }
};