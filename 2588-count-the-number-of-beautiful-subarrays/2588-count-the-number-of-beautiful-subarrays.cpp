class Solution {
public:
    //number of subarrays with xor of all elements equals to zero
  // we cant do in On*n so we have to do something else
    // if two prefixes have same xor means subarray btw them is having 0 as xor;
    // so if n prefixes have same xor then nC2 array will have xor 0
    // //     so store number of prefixes with different xors
    // //     map<xor,prefixes>
    // //     apply on map the formula
    // //     but if multiple prefixes have xor ==0
    //         then ans+=nC2+number of those prefixes also
    long long beautifulSubarrays(vector<int>& nums) {
         unordered_map<int,int> mp;
        
        int curr=0;
        
        long long count=0;
        for(int i=0;i<nums.size();i++){
            curr = curr^nums[i];
            
            if(curr == 0) count++;
            
            if(mp.find(curr) != mp.end()){
                count += mp[curr];
            }
                mp[curr]++;
        }
        
        return count;
    }
};