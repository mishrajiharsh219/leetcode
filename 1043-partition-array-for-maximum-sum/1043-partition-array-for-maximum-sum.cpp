class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
             int ans=INT_MIN;
        int maxi=INT_MIN;
        int n=nums.size();
        int len=0;
        for(int i=ind;i<min(n,ind+k);i++)
        {
            len++;
            maxi=max(maxi,nums[i]);
            long long sum=maxi*len;
            int cost=int(sum)+dp[i+1];
            ans=max(ans,cost);
        }
         dp[ind]=ans;
        }
        return dp[0];
    }
};