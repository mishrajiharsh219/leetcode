class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int maxsize=INT_MIN;
        int countzeroes=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==0)
            {
             countzeroes++;   
            }
            while(countzeroes>k){
             if(nums[start]==0)
                 countzeroes--;
             start++;   
            }
            maxsize=max(maxsize,end-start+1);
        }
        return maxsize;
    }
};