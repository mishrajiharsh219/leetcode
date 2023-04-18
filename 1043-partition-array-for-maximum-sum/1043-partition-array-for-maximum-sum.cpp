class Solution {
public:
    int solve(int ind,vector<int> &nums,int k,vector<int> &dp)
    {
        if(ind==nums.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int ans=INT_MIN;
        int maxi=INT_MIN;
        int n=nums.size();
        int len=0;
        for(int i=ind;i<min(n,ind+k);i++)
        {
            len++;
            maxi=max(maxi,nums[i]);
            long long sum=maxi*len;
            int cost=int(sum)+solve(i+1,nums,k,dp);
            ans=max(ans,cost);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};