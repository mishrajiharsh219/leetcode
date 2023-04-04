class Solution {
public:
    bool valid(int digit,vector<int> &c)
    {
        int count=0;
        for(auto i:c)
        {
            if(i>=digit)
                count++;
        }
        if(count>=digit)
            return true;
        return false;
    }
    int hIndex(vector<int>& c) {
       int low=0;
        int ans=0;
        int high=c.size();
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(valid(mid,c))
            {
                low=mid+1;
                ans=mid;
            }
            else
            {
            high=mid-1; 
            }
        }
        return ans;
    }
};