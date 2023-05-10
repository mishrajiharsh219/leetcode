class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0)
            return {};
        int rowbegin=0;
        int rowend=m-1;
        int colbegin=0;
        int colend=n-1;
        while(rowbegin<=rowend and colbegin<=colend)
        {
            
           for(int i=colbegin;i<=colend;i++){
               ans.push_back(matrix[rowbegin][i]);
           }
               rowbegin++;
            
            for(int i=rowbegin;i<=rowend;i++)
            {
                ans.push_back(matrix[i][colend]);
            }  
            colend--;
            
            if(rowbegin<=rowend){
            for(int i=colend;i>=colbegin;i--)
            {
                ans.push_back(matrix[rowend][i]);
            }  
            }
            rowend--;
        
            if(colbegin<=colend){
            for(int i=rowend;i>=rowbegin;i--)
            {
                ans.push_back(matrix[i][colbegin]);
            }  
            }    
            colbegin++;
        
        }
        return ans;
    }
};