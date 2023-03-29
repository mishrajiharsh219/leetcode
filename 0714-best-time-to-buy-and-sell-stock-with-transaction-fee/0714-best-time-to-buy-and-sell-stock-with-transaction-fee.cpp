class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int aheadzero,aheadone,currzero,currone;
        
        aheadzero=aheadone=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
        currone=max(-prices[ind]+aheadzero,0+aheadone);
        
        currzero=max(prices[ind]+aheadone-fee,0+aheadzero);
            
         aheadzero=currzero;
        aheadone=currone;
         }
        return aheadone;
    }
};