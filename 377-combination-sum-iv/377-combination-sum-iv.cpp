//for the folow up question we have to put a limit k to the numbe of times a number can 
//be used in combination
//suppose a=[-1,1] and target=1
//then we can have infinite combination of 1 and -1 =0 and one 1
//for this question we can use top down or bottom up approach dp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      vector<long long unsigned int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int n:nums){
                if(i>=n){
                    dp[i]+=dp[i-n];
                }
            }
        }
        return dp[target];
    }
};