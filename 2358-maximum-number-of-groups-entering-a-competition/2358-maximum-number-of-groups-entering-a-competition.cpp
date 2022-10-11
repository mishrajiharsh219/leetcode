//how many groups from 6 elements=3 at max 
// //  1: 1
//         2: 1
//         3: 2
//         4: 2
//         5: 2
//         6: 3
//         7: 3
//         8: 3
//         9: 3
//         10: 4
//the number of group formed depends solely on the size of the input array        
//         N*(N-1)//2
//if ina sorted array numer of elements of one array is greater than othewr then the sum will definetly be greater
//we can leave than condition 
class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        int n=nums.size();
        int ans=1;//1 group is definite
        int low=0,high=nums.size();
        while(low<=high){
           long mid=low+(high-low)/2;
            long x=(mid*(mid+1))/2;
            if(x<=n){
                ans=mid;
                low=mid+1;
            }
            else if(x>n){
                high=mid-1;
            }
        }
      return ans;
    }
};