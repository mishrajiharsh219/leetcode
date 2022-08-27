class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        int ans=INT_MIN;
        for(int start=0;start<m;start++){
            for(int end=start;end<m;end++){
                set<int> s={0};
                   int pre_sum=0;
                for(int i=0;i<n;i++){
                      int sum=matrix[i][end];
                if(start>0)
                    sum-=matrix[i][start-1];
                    pre_sum+=sum;
                    auto itr=s.lower_bound(pre_sum-k);
                    if(itr!=s.end())
                        ans=max(pre_sum-(*itr),ans);
                    s.insert(pre_sum);
                }
            }
        }
        return ans;
    }
};