class Solution {
public:
    int maxCoins(vector<int>& nums) {
    int org=nums.size();
	nums.insert(nums.begin(),1);
	nums.push_back(1);
	int newsize=nums.size();
	vector<vector<int>> dp(org+2,vector<int> (org+2,0));
    
    for(int i=org;i>=1;i--)
    {
        for(int j=1;j<=org;j++)
        {
            if(i>j)
                continue;
            int maxi=INT_MIN;
	    for(int ind=i;ind<=j;ind++)
	    {
		int cost=nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j];
		maxi=max(maxi,cost);

	}
	     dp[i][j]=maxi;
        }
    }
        return dp[1][org];
    }
};