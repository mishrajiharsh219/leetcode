class Solution {
public:
int solve(vector<int> &arr,int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 and arr[0]<=target)
    dp[0][arr[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            int nottake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            
            dp[i][j]=take+nottake;
        }
    }
    return dp[n-1][target];
}
    int findTargetSumWays(vector<int>& arr, int d) {
        int totalsum=0;
    for(auto c:arr)
    totalsum+=c;
     
     if(abs(d)>totalsum or (totalsum+d)%2!=0)
     return 0;
     
     int target=(totalsum+d)/2;
     

     return solve(arr,target);
    }
};