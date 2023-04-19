class Solution {
public:
    int solve(int ind,vector<int> nums,vector<int> &dp,unordered_map<int,int> &mp)
    {
        if(ind>=nums.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int take=0;
        int nottake=0;
        int i;
        if(ind==nums.size()-1)
            i=ind+1;
        else if(nums[ind+1]==nums[ind]+1)
            i=ind+2;
        else
            i=ind+1;
        
        int count=mp[nums[ind]];
        take=count*nums[ind]+solve(i,nums,dp,mp);
        nottake=solve(ind+1,nums,dp,mp);
        return dp[ind]=max(take,nottake);
    }
    int deleteAndEarn(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(auto c:nums)
        {
            mp[c]++;
        }
        nums.clear();
        for(auto c:mp)
        {
            nums.push_back(c.first);
        }
         sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp,mp);
    }
};