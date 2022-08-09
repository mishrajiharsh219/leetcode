class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int size=0;
        vector<int> tail(n);
        for(int x:nums){
            int i=0,j=size;
            while(i!=j){
                 int m=(i+j)/2;
                if(tail[m]>=x){
                    j=m;
                }
                    else
                        i=m+1;
                }
                tail[i]=x;
            if(size==i)
                size++;
        }
        return size;
    }
};