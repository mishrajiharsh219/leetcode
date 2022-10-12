class Solution {
public:
    bool isvalid(vector<int> &nums,int curr_min,int maxoperations){
        int operations=0;
        for(int i=0;i<nums.size();i++){
            operations+=(nums[i]/curr_min);
            if(nums[i]%curr_min==0){
                operations--;
            }
        }
        if(operations<=maxoperations)
            return true;
        else
            return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
  int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(nums,mid,maxOperations)){
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};