class Solution {
public:
    bool valid(vector<int> w,int mid,int days)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            if(sum>mid)
            {
                count++;
                sum=w[i];
            }
        }
        if(count>days)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int mincap=*max_element(weights.begin(),weights.end());
        int maxcap=0;
        for(int i=0;i<n;i++)
            maxcap+=weights[i];
        int low=mincap;
        int high=maxcap;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(valid(weights,mid,days))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};