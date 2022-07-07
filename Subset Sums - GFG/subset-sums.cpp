// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
     void subsum(vector<int> &res,int i,int n,vector<int> &a,int sum){
         if(i==n){
             res.push_back(sum);
             return;
         }
         sum+=a[i];
         subsum(res,i+1,n,a,sum);
         sum-=a[i];
         subsum(res,i+1,n,a,sum);
     }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> res;
       int i=0,sum=0;
      subsum(res,i,N,arr,sum);
      sort(res.begin(),res.end());
      return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends