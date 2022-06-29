class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        vector<int> bit(32,0);
        for(int i=0;i<32;i++){
          
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i))
                    bit[i]++;
            }
        }
         for(int i=0;i<32;i++){
           if(bit[i]%3==1){
               res+=(1<<i);
           }
            }
        return res;
    }
};