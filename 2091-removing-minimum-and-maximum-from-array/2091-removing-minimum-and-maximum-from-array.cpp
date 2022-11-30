class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
         int min_index = 0, max_index = 0, min_num = INT_MAX, max_num = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > max_num){
                max_num = nums[i];
                max_index = i;
            }
            if(nums[i] < min_num){
                min_num = nums[i];
                min_index = i;
            }
        }
        
        int n_deletions = 0;
        
        // both from left
        n_deletions = max(min_index, max_index) + 1;
        
        // both from right
        int deletions_from_right = nums.size() - min(min_index, max_index);
        n_deletions = min(n_deletions, deletions_from_right);
        
        // min_index from left and max_index from right
        int deletions_from_left = min(min_index, max_index) + 1;
        deletions_from_right = nums.size() - max(min_index, max_index);
        int total_deletions = deletions_from_left + deletions_from_right;
        
        n_deletions = min(n_deletions, total_deletions);
        
        return n_deletions;
    }
};