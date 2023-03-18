class Solution {
public:
    bool carfeas(long long time,int car,vector<int> r)
    {
        for(auto c:r)
        {
            long long temp=time/c;
            long long carbyone=sqrt(temp);
            car-=carbyone;
            if(car<=0)return true;    
        }
        if(car==0)
            return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0;
        long long h=1e18;
        long long ans=0;
        while(l<h)
        {
            long long mid=l-(l-h)/2;
            if(carfeas(mid,cars,ranks))
                h=mid;
            else
                l=mid+1;
        }
        return h;
    }
};