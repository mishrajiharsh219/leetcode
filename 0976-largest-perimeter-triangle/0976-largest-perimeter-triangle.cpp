//sum of any two sides of atriangle is greater than the third side
//meansa+b>c and b+c>a and c+a>b
//if we proof smallest two sides of triangle sum> biggest sides then all conditions are automatically fullfilled
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>1;i--){
            if(nums[i-1]+nums[i-2]>nums[i]){
                return nums[i-1]+nums[i-2]+nums[i];
            }
        }
        return 0;
    }
};