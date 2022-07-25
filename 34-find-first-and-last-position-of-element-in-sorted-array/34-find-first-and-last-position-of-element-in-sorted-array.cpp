class Solution {
public:
    int lowerbound(int target,int n,vector<int> &nums){
        int low=0;int end=n-1;
        while(low<=end){
             int mid=(((end-low)/2)+low);
        if(nums[mid]<target)
            low=mid+1;
        else
            end=mid-1;
    }
    return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=lowerbound(target,n,nums);
        int second=lowerbound(target+1,n,nums)-1;
        if(first>=n or first<0 or second<0 or second>=n or nums[first]!=target or nums[second]!=target )
            return {-1,-1};
        return {first,second};
    }
};
















// vector<int> searchRange(vector<int>& nums, int target) {
//     int idx1 = lower_bound(nums, target);
//     int idx2 = lower_bound(nums, target+1)-1;
//     if (idx1 < nums.size() && nums[idx1] == target)
//         return {idx1, idx2};
//     else
//         return {-1, -1};
// }

// int lower_bound(vector<int>& nums, int target) {
//     int l = 0, r = nums.size()-1;
//     while (l <= r) {
//         int mid = (r-l)/2+l;
//         if (nums[mid] < target)
//             l = mid+1;
//         else
//             r = mid-1;
//     }
//     return l;
// }