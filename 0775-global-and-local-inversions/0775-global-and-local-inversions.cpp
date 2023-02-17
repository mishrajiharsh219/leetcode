class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        //we can see that [0,1,......,n-1] so permutaion of this
        //gloval inversion-> some number right to present should be less than present
        //local inversion -> just right number should be less than present
        //[1,0,2] here shifting of 1 on left by 1 makes 1 to have inversion
        //[0,2,1] here shifting of 1 on right by 1 makes 2 to have inversion
        //more than 1 shift in any element will result in inequal inversions
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i]-i)>1)
                return false;
        }
        return true;
    }
};