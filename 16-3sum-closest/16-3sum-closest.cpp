class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
       int closest=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int first=0;first<nums.size()-2;first++){
            int second=first+1;
            int third=n-1;
            while(second<third){
                int currsum=nums[first]+nums[second]+nums[third];
                if(currsum==target)
                    return target;
                if(abs(target-currsum)<abs(target-closest))
                    closest=currsum;
                if(currsum<target)
                    second++;
                if(currsum>target)
                    third--;
            }
        }
        return closest;
    }
};