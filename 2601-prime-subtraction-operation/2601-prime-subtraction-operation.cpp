class Solution {
public:
    int find(int a,int b,vector<int> &v){
        int diff=a-b;
        int ind=upper_bound(v.begin(),v.end(),diff)-v.begin();
        if(ind==v.size())
            return -1;
        return v[ind];
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
         vector<bool> primes(1000,true);
    for(int i=2;i*i<=1000;i++)
    {
        if(primes[i]==true)//unmarked
        {
            for(int j=i*i;j<=1000;j+=i)
                primes[j]=false;
        }
    }
         vector<int>v;
        for(int i=2;i<=1000;i++){
            if(primes[i])v.push_back(i);
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                continue;
            else
            {
                int prime=find(nums[i],nums[i+1],v);
                if(prime==-1)
                    return false;
                if(prime<nums[i])
                nums[i]=nums[i]-prime;
                else
                return false;
            }
        }
        return true;
    }
};