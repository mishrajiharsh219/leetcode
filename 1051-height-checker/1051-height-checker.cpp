class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> count(101,0);
        
        for(auto h:heights)
        {
         count[h]++;   
        }
        int hptr=1;
        
        int ans=0;
        for(auto h:heights)
        {
          while(count[hptr]==0) hptr++;
            
            if(hptr!=h)
                ans++;
            
            count[hptr]--;
        }
        return ans;
    }
};