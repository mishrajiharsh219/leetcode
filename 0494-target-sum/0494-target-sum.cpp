class Solution {
public:
int solve(vector<int> &arr,int target)
{
    int n=arr.size();
    vector<int> prev(target+1,0);
    
    if(arr[0]==0)
        prev[0]=2;
    else
        prev[0]=1;
    if(arr[0]!=0 and arr[0]<=target)
    prev[arr[0]]=1;

    for(int i=1;i<n;i++)
    {
         vector<int> temp(target+1,0);
        for(int j=0;j<=target;j++)
        {
            int nottake=prev[j];
            int take=0;
            if(arr[i]<=j)
                take=prev[j-arr[i]];
            
            temp[j]=take+nottake;
        }
        prev=temp;
    }
    return prev[target];
}
    int findTargetSumWays(vector<int>& arr, int d) {
        int totalsum=0;
    for(auto c:arr)
    totalsum+=c;
     
     if(abs(d)>totalsum or (totalsum+d)%2!=0)
     return 0;
     
     int target=(totalsum+d)/2;
     

     return solve(arr,target);
    }
};