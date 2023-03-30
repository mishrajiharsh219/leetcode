class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return {};
        sort(nums.begin(),nums.end());
        int maxi=1;
        int lastindex=0;
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int> lds;
        lds.push_back(nums[lastindex]);
        while(lastindex!=hash[lastindex])
        {
            lastindex=hash[lastindex];
            lds.push_back(nums[lastindex]);
        }
        reverse(lds.begin(),lds.end());
        return lds;
    }
};