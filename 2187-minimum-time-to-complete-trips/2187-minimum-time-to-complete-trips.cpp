class Solution {
public:
   long long int trips(long long int time,vector<int> v)
    {
        long long int ans=0;
        for(auto c:v)
        {
            ans+=abs(time/c);
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totaltrips) {
        long long int low=0;   
        long long int ans=0;
        long long int mini=*min_element(time.begin(),time.end());
        long long int high=mini*totaltrips;
        while(low<high)
        {
            long long int mid=(low+high)/2;
            cout<<mid<<" ";
            if(trips(mid,time)<totaltrips)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return high;
    }
};