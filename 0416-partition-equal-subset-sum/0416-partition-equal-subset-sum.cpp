class Solution {
public:
    
    //same as subset sum equal to k in codestudio or see in copy
    bool value(vector<int> nums,int k)
    {
        int n=nums.size();
        
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }     
        if(nums[0]<=k)
            dp[0][nums[0]]=true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<k+1;j++)
            {
                bool take=false,nottake=false;
                
                nottake=dp[i-1][j];
                if(j>=nums[i])
                take=dp[i-1][j-nums[i]];
                
                dp[i][j]=take or nottake;
            }
        }
        
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {

        int totsum=0;
        for(auto c:nums)
            totsum+=c;
        
        if(totsum%2)
            return false;
        return value(nums,totsum/2);
    }
};