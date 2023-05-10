class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int temp=1;
        if(n==1)
            return {{1}};
        vector<vector<int>> mat(n,vector<int>(n,0));
        int rowbegin=0;
        int colbegin=0;
        int rowend=n-1;
        int colend=n-1;
        while(rowbegin<=rowend and colbegin<=colend)
        {
            for(int i=colbegin;i<=colend;i++)
            {
                mat[rowbegin][i]=temp;
                temp++;
            }
            rowbegin++;
            for(int i=rowbegin;i<=rowend;i++)
            {
                 mat[i][colend]=temp;
                temp++;
            }
            colend--;
            if(rowbegin<=rowend){
            for(int i=colend;i>=colbegin;i--)
            {
                mat[rowend][i]=temp;
                temp++;
            }
            }
            rowend--;
            if(colbegin<=colend)
            {
             for(int i=rowend;i>=rowbegin;i--)
             {
                 mat[i][colbegin]=temp;
                 temp++;
             }
            }
            colbegin++;
        }
            return mat;
    }
};