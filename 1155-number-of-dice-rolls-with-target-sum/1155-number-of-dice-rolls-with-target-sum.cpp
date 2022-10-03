class Solution {
public:
 int numRollsToTarget(int n, int k, int target) {
    __int128 m = 1000000007;
    if (n * k < target) return 0;
    if (n * k == target) return 1;
    __int128 dp[n + 1][target + 1];
    memset(dp, 0, sizeof(__int128) * (n + 1) * (target + 1));
    for (int i = 1; i <= k && i <= target; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= target; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % m;
            if (j - k > 0) dp[i][j] -= dp[i - 1][j - k - 1] - m;
        }
    } 
    return dp[n][target] % m;
}
};