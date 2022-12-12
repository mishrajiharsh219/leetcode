class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        
        set<int> s;
        for(auto v:nums){
            s.insert(v);
        }
        for(int i=0;i<n;i++){
            int temp=0;
            long long t=nums[i];
           long long int sq=t*t;
            bool flag=false;
            if(s.find(sq)!=s.end())
                flag=true;
             while(flag){
                 if(temp==0)temp+=2;
                 else
                     temp++;
                 if(sq>320) break;
                 sq=sq*sq;
                  s.erase(t);
                  if(s.find(sq)==s.end())
                flag=false;
             }
            ans=max(ans,temp);
        }
        if(ans<2)
            return -1;
        return ans;
    }
};