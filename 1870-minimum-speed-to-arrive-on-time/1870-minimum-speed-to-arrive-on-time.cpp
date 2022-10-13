// //since it is given that
// 1 <= n <= 10^5
// 1 <= dist[i] <= 10^5
// 1 <= hour <= 10^9
// so we know that minimum speed can be 1 because1*1
//     and max is given to not exceed 10^7
//speed=dist/time so time=dist/speed
class Solution {
public:
    bool valid(vector<int> &dist,double hour, int mid){
        double hourreq=0;
        for(int i=0;i<dist.size()-1;i++){
            hourreq+=ceil((double)dist[i]/mid);
        }
        hourreq+=(double)dist[dist.size()-1]/mid;
        if(hourreq<=hour){
            return true;
        }
            return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour<=(double)dist.size()-1)
            return -1;
        int res=0;
        int low=1;
        int high=1e7;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(dist,hour,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};