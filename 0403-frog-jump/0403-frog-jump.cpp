class Solution {
public:
    // dp[i][j] means we can/cant make jump of j from ith stone
    //to reach a stone we can in worst case jump from 1 
    // ex: from 1 to 20 we need 19 jump no more jump can be neeeded beacuse 0 can make only 1 jump to 1
    //so for 2 elements only max jump can be 1 [0,1]                   1    2   3
    //for 4 elements only max jump will be 3 | jumps at max|:[1,2,3]=[0->12->23->34] doesnt matter what stones[i] is everytime jump can increase by 1 only
    // so jump will vary from 1 to stones.size()-1
    // so dp[index][jumpsize];= dp[n][n];
    
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        
        vector<vector<int>>dp(n, vector<int>(n, false));
        dp[0][1] = true;  //we can make jump of 1 from 0 forsure
        
        for (int i = 1; i < n; i++) {             //indexes
            for(int j = 0; j < i; j++) {          //previous indexes from where we can reach i
                int d = stones[i] - stones[j];    //distance of jump needed from j to i
                if (d > 0 && d < n && dp[j][d]) {    //if we can make jump of distance needed from j hence we can reach i;
                    if (i == n-1) return true;       //if indexd reached is n-1 means job done
                    dp[i][d] = true;                  //for future we can make jump of distance of d from i because prev jump was d
                    if (d+1 < n) dp[i][d+1] = true;      //we can make jump of distance of d+1 from i because prev jump was d
                    if (d-1 < n) dp[i][d-1] = true;      //we can make jump of distance of d-1 from i because prev jump was d 
                }
            }
        }
        
        return false;     //checked for all indexes never reached last index or cant reach last element from any previous element
    }
};