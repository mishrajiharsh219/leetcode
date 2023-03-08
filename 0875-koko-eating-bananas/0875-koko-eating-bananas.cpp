class Solution {
public:
    int time(vector<int> piles, int k)
    {
        int h = 0;
        if(k == 0) return INT_MAX;
        for(int i : piles)
        {
            if(i % k != 0)
            {
                h++;
            }
            h += (i / k);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    
        long long sum=0;
         for(int i = 0; i < piles.size(); i++)
        {
            sum += piles[i];
        }
        int low=sum/h;
      
        int high=*max_element(piles.begin(),piles.end());
        
     int ans=high;
        while(low<high)
    {
        int mid=low-(low-high)/2;
         if(time(piles,mid)<=h)
         {
             high=mid;
             ans=mid;
         }
        else
        {
            low=mid+1;                
        }
    }
        return ans;
    }
};