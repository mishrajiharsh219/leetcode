//binary search over solution domain
//finding first bad version over solution type question
class Solution {
public:
 bool helper(int mid,vector<int>& weights,int days){
      int count=1;
     int sum=0;
     for(int i=0;i<weights.size();i++){
         sum+=weights[i];
         if(sum>mid){
             count++;
            sum=weights[i];
         }
     }
     if(count<=days)
         return true;
     return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int ans=0;
        int maxcap=0;//can be done in single day,day=1;
        int mincap=*max_element(weights.begin(),weights.end());//if single element each day,days=n
        for(int i=0;i<weights.size();i++){
            maxcap+=weights[i];
        }
        int high=maxcap;
        int low=mincap;
        while(low<high){
            int mid=low + (high-low)/2;
            if(helper(mid,weights,days)){
                high=mid;
            }
            else
            low=mid+1;
        }
        return low;
    }
};