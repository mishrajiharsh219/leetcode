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
    void dfs(TreeNode* root, vector<int> &temp){
        if(root==NULL)
            return;
        temp.push_back(root->val);
        dfs(root->left,temp);
        dfs(root->right,temp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;
        dfs(root,temp);
     sort(temp.begin(),temp.end());
        int i=0,j=temp.size()-1;
        while(i<j){
            if((temp[i]+temp[j])==k)
                return true;
            if((temp[i]+temp[j])>k)
                j--;
            else
                i++;
        }
         return false;
    }
};