class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=1;
        int high=num;
        while(low<=high){
            int mid=low+(high-low)/2;
            int res=num/mid,remain=num%mid;
            if(res==mid and remain==0)
                return true;
            else if (res>mid)
            {
                  low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return false;
    }
};