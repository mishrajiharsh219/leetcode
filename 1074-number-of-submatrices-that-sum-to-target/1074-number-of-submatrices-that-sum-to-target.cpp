class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
       int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
           matrix[i][j]+=matrix[i][j-1];
        }
    }
unordered_map<int,int> mp;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        mp={{0,1}};
        int sum=0;
        for(int k=0;k<m;k++){
            sum+=matrix[k][j];
            if(i>0)
            sum-=matrix[k][i-1];
            if(mp.find(sum-target)!=mp.end())
                ans+=mp[sum-target];
            mp[sum]++;
        }
    }
}
    return ans;
}
};