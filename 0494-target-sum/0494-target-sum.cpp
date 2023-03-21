class Solution {
public:
    int mod=1e9+7;
int find(int ind,int target,vector<int> arr,vector<vector<int>> &dp)
{
    if(ind==0)
    {
      if(target==0 and arr[0]==0)
      return 2;
       if(target==arr[0])
      return 1;
      if(target==0)
      return 1;
      return 0;
    }

    if(dp[ind][target]!=-1)
    return dp[ind][target];

     int take=0,nottake=0;

     nottake=find(ind-1,target,arr,dp);
     if(arr[ind]<=target)
     take=find(ind-1,target-arr[ind],arr,dp);

     return dp[ind][target]=(take+nottake)%mod;

}
int solve(vector<int> &arr,int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return find(n-1,target,arr,dp);
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