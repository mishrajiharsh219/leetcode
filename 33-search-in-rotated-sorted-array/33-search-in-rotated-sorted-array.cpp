class Solution {
public:
  int find_min(vector<int> &nums){
      int mid;
        int start=0,end=nums.size()-1;
     
        while(start<end){
               if(nums[start]<=nums[end]){
                return start;
            }
           mid=start+(end-start)/2;
           
           if(nums[start]<=nums[mid]){
                start=mid+1;
            }
            else
                end=mid;
        }
        return start;
    }
    int bs(vector<int> &nums,int start,int end,int target){
        int res;
        while(start<=end){
           int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int min=find_min(nums);
        int ans=-1;
        int start=0,end=n-1;
        if(start==end){
            if(nums[start]==target)
                return 0;
            else
                return -1;
        }
        if(nums[start]<nums[end])
            ans=bs(nums,start,end,target);
       else if(target>=nums[start])
           ans=bs(nums,start,min,target);
        else if(target<=nums[end])
            ans=bs(nums,min,end,target);
        return ans;
    }
};