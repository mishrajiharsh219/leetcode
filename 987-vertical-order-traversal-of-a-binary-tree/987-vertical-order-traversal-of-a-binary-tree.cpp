//print on the basis of levelwise and vertical line wise and (x,y) coordinate
//print nodes in same line in sorted manner
//we will use map of map of set 
//map will have (x,y) coordinate 
//multiset will have in sorted manner and solve multiple elements

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,map<int,multiset<int>>> mp;
    void dfs(TreeNode* curr,int col,int row){
        if(!curr){
            return;
        }
       mp[col][row].insert(curr->val);
        dfs(curr->left,col-1,row+1);
        dfs(curr->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      dfs(root,0,0);  
        
        vector<vector<int>> ans;
         for(auto m1: mp)
        {    
            ans.push_back(vector<int>());
            for(auto m2: m1.second)
            {
                for(auto m3: m2.second)
                    ans.back().push_back(m3);
            }
        }
        return ans;
        
    }
};