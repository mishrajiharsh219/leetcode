   class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
                int n=nums.size();
  
        int p=1<<n;
        //power set will have 2^n elements
      vector<vector<int>> res(p);

        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                 if ((i >> j) & 1) {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
}; 

