class Solution {
public:
    //repeating elements before ans will make pattern : even odd even odd.....
    //repeating elements after ans will make pattern : odd even odd even....
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(mid==0 and nums[mid]!=nums[mid+1])   //first element
                return nums[mid];
            else if(mid==n-1 and nums[mid]!=nums[mid-1])
                return nums[mid];                  //last element
            else if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) //answer
                return nums[mid];
            else if(mid%2==0)  //mid is even
            {
                if(nums[mid]==nums[mid+1])//even odd pattern
                    low=mid+1;
                else
                    high=mid-1;
            }
            else       //if mid is odd
            {
                if(nums[mid]==nums[mid-1])//even odd continues
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};