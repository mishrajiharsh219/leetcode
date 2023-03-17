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
        long long ans=0;
        unordered_map<long long,long long> mp;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x=x^nums[i];
            if(mp.find(x)!=mp.end())
                mp[x]++;
            else
                mp[x]=1;
        }
     
        for(auto it:mp)
        {
            long long i=it.first;
            long long j=it.second;
            if(i==0)
                ans+=(j*(j+1))/2;
            else
                ans+=(j*(j-1))/2;
        }
        return ans;
    }
};