class Solution {
public:
    void rotate(vector<vector<int>> &mat){
         int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
                swap(mat[i][j],mat[j][i]);
        }
    for(int i=0;i<n;i++){
        int start=0;
        int end=m-1;
        while(start<end){
            swap(mat[i][start],mat[i][end]);
            start++;
            end--;
        }
    }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
         if(mat==target)
            return true;
       rotate(mat);
        if(mat==target)
            return true;
         rotate(mat);
        if(mat==target)
            return true;
         rotate(mat);
        if(mat==target)
            return true;
         return false;
    }
};