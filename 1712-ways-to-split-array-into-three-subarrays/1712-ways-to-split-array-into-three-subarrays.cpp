// consider --> (1,1,1) by this example we can understand we can divide it by (1),(1),(1)
// so basically to get sum of subarrays we will use prefix sum array right!, then 

// 1,to satisfy 2nd part greater than first part,its value must be min of first part ,so we choose the index of lower bound of left part sum L[i],
// 2,ans same to third part 2nd part value should can have max of third part value,which is half of remaining sum ,as we already cutted l[i]

// just try to understand clearly by pen and paper using this example: (1,2,2,5,0)
// here sum is 12
// prefix sum array is (1 3 5 10 10)
// so here
// case one:left part: 1
// then middle part prefix sum should have atleast 2*1=2;
// and max can go upto half of remaning sum,as rest half would be third part right?,are you getting it?
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        vector<int>pre(n,0);
        pre[0]=nums[0];
        
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        
        long long int ans=0;
        int l,r;
        for(int i=0;i<nums.size();i++)
        {
          l=pre[i];
          r=pre[nums.size()-1]-l;
          int x=lower_bound(pre.begin()+i+1,pre.end(),2*l)-pre.begin();
          int y=upper_bound(pre.begin()+i+1,pre.begin()+nums.size()-1,l+r/2)-pre.begin();
            
            if(y>x)
                ans+=y-x;
        }
        return ans%1000000007;
    }
};