// // Iterate over the original list, but check if the previous element is the same as current. 
// // We need to make this check because using the same element will give us the same result as last iteration.
// void backtrack2(vector<int>& nums, vector<int>& temp,
//                   vector<vector<int>>& res, unordered_map<int, int>& freq) {
//         if (temp.size() == nums.size()) {
//             res.push_back(temp);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (freq[nums[i]] == 0 || (i != 0 && nums[i] == nums[i - 1])) continue;
//             temp.push_back(nums[i]);
//             freq[nums[i]]--;
//             backtrack(nums, temp, res, freq);
//             freq[nums[i]]++;
//             temp.pop_back();
//         }
//     }
class Solution {
public:
    void backtrack(set<vector<int>> &res,vector<int> &ds,vector<int> &nums,vector<int> &freq)
    {
        if(nums.size()==ds.size()){
            res.insert(ds);
        }
        for(int i=0;i<nums.size();i++){
         if(!freq[i]){
          ds.push_back(nums[i]);
             freq[i]=1;
             backtrack(res,ds,nums,freq);
             freq[i]=0;
             ds.pop_back();
         }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        backtrack(res,ds,nums,freq);
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
};