class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &jobs,int days,int i,int n){
        if(days==1){
            return *max_element(jobs.begin()+i,jobs.end());
        }
        if(dp[i][days]!=-1){
            return dp[i][days];
        }
        int result=INT_MAX;
        int currdiff=INT_MIN;
        for(int j=i;j<=n-days;j++){
            currdiff=max(currdiff,jobs[j]);
            result=min(result,currdiff+solve(jobs,days-1,j+1,n));
        }
        dp[i][days]=result;
        return dp[i][days];
    }
    int minDifficulty(vector<int>& jobs, int d) {
        memset(dp,-1,sizeof(dp));
        if(jobs.size()<d)
            return -1;
        return solve(jobs,d,0,jobs.size());
    }
};