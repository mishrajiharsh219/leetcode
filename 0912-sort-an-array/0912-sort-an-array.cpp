class Solution {
public:
    void merge(vector<int> &nums,int firstbegin,int firstend,int secfirst,int secend){
      vector<int> l,r;
        int i=0,j=0;
        for(int i=firstbegin;i<=firstend;i++)
            l.push_back(nums[i]);
         for(int i=secfirst;i<=secend;i++)
            r.push_back(nums[i]);
        int n=l.size();
        int m=r.size();
        int k=firstbegin;
        while(i<n and j<m){
            if(l[i]<r[j])
            { nums[k++]=l[i++];}
            else
            {
                nums[k++]=r[j++];}
        }
        while(i<n){nums[k++]=l[i++];}
    
        while(j<m){nums[k++]=r[j++];}
    }
    void merge_sort(vector<int> &nums,int begin,int end)
    {
        if(begin>=end)
            return;
        if(begin<end)
        {
            int mid=(end+begin)/2;
            merge_sort(nums,begin,mid);
            merge_sort(nums,mid+1,end);
            merge(nums,begin,mid,mid+1,end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        merge_sort(nums,0,n-1);
        return nums;
    }
};