class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(auto x:nums){
            if(x>=0)
                pos.emplace_back(x);
            else
                neg.emplace_back(x);
        }
        int i=0,j=0,c=0;
        int n=nums.size();
        while(c<n){
            if(j==i){
                nums[c++]=pos[i++];
            }
            else
                nums[c++]=neg[j++];
        }
        return nums;
    }
};