class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int i=0;
        while(i<nums.size()){
            if(s.find(original)==s.end()){
                return original;
            }
            else
                original*=2;
        }
        return original;
    }
};