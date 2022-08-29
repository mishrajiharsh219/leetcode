class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       int n=mat.size();
        int m=mat[0].size();
        int rowindex=0;
        int colindex;//diagonal at col=0 and row=0 is same
        int diagonals=n+m-1;
        for(int i=1;i<=diagonals;i++){
            vector<int> diagonal;
            
            if(i<=m){
                colindex=m-i;
            }
            else{
                rowindex++;
                colindex=0;
            }
            for(int i=rowindex,j=colindex;i<n and j<m;i++,j++){
                diagonal.push_back(mat[i][j]);
            }
            sort(diagonal.begin(),diagonal.end());
            for(int i=rowindex,j=colindex,k=0;i<n and j<m;i++,j++,k++){
                mat[i][j]=diagonal[k];
            }
        }
        return mat;
    }
};