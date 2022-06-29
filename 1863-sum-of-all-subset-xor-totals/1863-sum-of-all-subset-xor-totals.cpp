class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int p=0,ans1=0;
        int ans2=0;
        
        for(int i=0;i<32;i++){
            int countz=0;
            int countO=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i))
                    countO++;
                else
                    countz++;
            }
            if(countO)
            { p=(1<<(countO-1))*(1<<countz);
            ans+=p*(1<<i);}
        }
            return ans+ans1+ans2;
    }
};



   // int subsetXORSum(vector<int>& nums) 
   //  {
   //      int ans=0;
   //      for(int i=0; i<32; i++)
   //      {
   //          int mask=1<<i;
   //          int count=0;
   //          for(int j=0; j<nums.size(); j++)
   //          {
   //              if(nums[j]&mask) count++;
   //          }
   //          if(count)
   //          {
   //              ans+=mask*(1<<(count-1))*(1<<(nums.size()-count));
   //          }
   //      }
   //      return ans;
   //  }