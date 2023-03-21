class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       vector<long long> prev(amount+1,0);
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                prev[i]=i/coins[0];
            else
                prev[i]=INT_MAX;
        }
        vector<long long> temp(amount+1,0);
        for(int i=1;i<n;i++)
        {
        for(int j=0;j<=amount;j++)
        {
             long long nottake=INT_MAX,take=INT_MAX;
         nottake=0+prev[j];
        if(coins[i]<=j)
        take=1+temp[j-coins[i]];
        
         temp[j]=min(take,nottake);
        }
            prev=temp;
        }
        if(prev[amount]==INT_MAX)
            return -1;
        return prev[amount];
    }
};