class Solution {
public:
    bool isprime(int n)
    {
          if (n <= 1)
        return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int find(int a,int b){
        for(int i=2;i<a;i++)
        {
            if(isprime(i))
            {
                if((a-i)<b)
                    return i;
            }
        }
        return -1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                continue;
            else
            {
                int prime=find(nums[i],nums[i+1]);
                if(prime==-1)
                    return false;
                nums[i]=nums[i]-prime;
            }
        }
        return true;
    }
};