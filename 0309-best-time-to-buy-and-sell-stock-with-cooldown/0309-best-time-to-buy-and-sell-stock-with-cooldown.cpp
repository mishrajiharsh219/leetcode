class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
         vector<int> ahead(2,0);  //i+1th
        vector<int> curr(2,0);   //ith
        int aheadnextone=0;  //i+2th [1]
        
        ahead[0]=ahead[1]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+ahead[0],0+ahead[1]);
        }
        else
        {
            profit=max(prices[ind]+aheadnextone,0+ahead[0]);
        }
         curr[buy]=profit;
            }
            aheadnextone=ahead[1];
            ahead=curr;
        }
        return ahead[1];
    }
};