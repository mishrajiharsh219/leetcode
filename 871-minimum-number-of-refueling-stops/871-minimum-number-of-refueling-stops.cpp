class Solution {
public:
      int minRefuelStops(int target, int cur, vector<vector<int>> s) {
     int n=s.size();
          long dp[501]={cur};
          for(int i=0;i<n;i++){
              for(int t=i;t>=0 and dp[t]>=s[i][0];t--){
                  dp[t+1]=max(dp[t+1],dp[t]+s[i][1]);
              }
          }
          for(int i=0;i<n+1;i++)
          {
              if(dp[i]>=target)
                  return i;
          }
    return -1;
      }
};