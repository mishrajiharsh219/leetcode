// DP
// from 3 state to 2 state
class Solution {
public:
    int dp[1001][1001];   // l and op both can go upto power 3
    int solve(int l , vector<int>&nums , vector<int>&mul ,int n , int m, int op ){
        int r = n-1 - (op -l);
        if(l>r or op==m) return 0;
        if(l==r) return mul[op]*nums[l];
        
        if(dp[l][op]!=0x7f7f7f7f) return dp[l][op];  /////////////////////////////////// and here
        
        int ans = INT_MIN;
        
        ans = max(ans , nums[l]*mul[op] + solve(l+1 , nums , mul , n , m , op+1));
        ans = max(ans , nums[r]*mul[op] + solve(l , nums, mul , n , m , op+1));

        return dp[l][op] = ans;
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int m = mul.size();
        int n = nums.size();
        int l = 0;
        int r = n-1;
        memset(dp , INT8_MAX , sizeof dp);  /////////////////////////////////// I changed here
        return solve(l  , nums , mul , n ,m ,0);
        
    }
};