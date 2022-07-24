//search from the top-right element and reduce the search space by one row or column at each time.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int m=matrix.size();
        int n=matrix[0].size();
        int r=0,c=n-1;
        while(r<m and c>=0){
            if(matrix[r][c]>target)
                c--;
            else if(matrix[r][c]<target)
                r++;
            else
                return true;
        }
        return false;
        
    }
};