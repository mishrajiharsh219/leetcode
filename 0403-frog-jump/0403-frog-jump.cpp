class Solution {
public:
    //check memo soln for my real thinking and mle soln
    //let dp[i][j] denote at stone i, the frog can or cannot make jump of size j
    // The maximum jump size the frog can make at each stone if possible is shown as followings: 
// stone:      0, 1, 2, 3, 4, 5
// jump size:  1, 2, 3, 4, 5, 6 (suppose frog made jump with size k + 1 at each stone)

    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N, vector<bool> (N+1, false));
        dp[0][1] = true;  //at index 0 jump of 1 is possible
        
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff > N || !dp[j][diff]) 
                    continue;
                
                if(i == N - 1) 
                    return true;
                
                dp[i][diff] = true;
                if(diff - 1 >= 0) dp[i][diff - 1] = true;
                if(diff + 1 <= N) dp[i][diff + 1] = true;
            }
        }

        return false;
    }
};
