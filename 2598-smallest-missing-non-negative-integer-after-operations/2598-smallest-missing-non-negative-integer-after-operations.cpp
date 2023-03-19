class Solution {
public:
    // to find maimum mmex from nums we need to convert each num[i] int o smallest positive integer possible by subtractig or adding "value"
    //find least positive value for every posive number
    //find least positive value for every negative number
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int> mp;
     //converting every number into smallest +ve possible
        
        for(int i=0;i<n;i++)
        {
        int num=nums[i];
            if(num<0)
            {
                //we are doing num+value because num%value can give us -ve also 
                //ex: -12 % 5 = -2
                //so to make it positive add 5 =3
                //and 3%5=3 nly
                num=(num%value)+value;
                num=num%value;
            }
            else
            {
                num=num%value;
            }
            mp[num]++;    //storing number of rems because one number can be used multiple times
        }
        
    // finding max mex in nums
        
        int ans=0,req=0;
        while(1)
        {
        if(mp[req]>0)
        {
            mp[req]--;
            ans++;
        }
        else
        {
            break;            
        }
        req=(req+1)%value;
         }
     return ans;
    }
};