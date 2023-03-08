class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
      long long n=ranges.size();
        long long mod=1e9+7;
        long long i=0;
        int ans=2;  //beacuse 2 grps are gonna be there either empty or not 
        sort(ranges.begin(),ranges.end());
        int second=ranges[0][1];
        for(int i=1;i<n;i++)
        {
            if(ranges[i][0]<=second)
            {
                second=max(second,ranges[i][1]);
            }
            else
            {
                second=ranges[i][1];
                ans=(ans*2)%mod;
            }
        }
        return ans;
    }
};