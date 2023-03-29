class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int currnotbuy=0,currbuy=0,nextnotbuy=0,nextbuy=0;
        

      for(int ind=n-1;ind>=0;ind--)
      {
             
            currbuy=max(-prices[ind]+nextnotbuy,0+nextbuy);
          
            currnotbuy=max(prices[ind]+nextbuy,0+nextnotbuy);
          
          nextnotbuy=currnotbuy;
          nextbuy=currbuy;
          }
      return nextbuy;
    }
};