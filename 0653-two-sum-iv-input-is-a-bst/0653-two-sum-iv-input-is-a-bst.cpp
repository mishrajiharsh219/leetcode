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
            vector<int> inorder1;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i=0,j=inorder1.size()-1;
        while(i<j){
            if((inorder1[i]+inorder1[j])==k)
                return true;
            else if((inorder1[i]+inorder1[j])>k)
            j--;
            else
                i++;
        }
        return false;
    }
    void inorder(TreeNode* root){
       if(root->left)
        inorder(root->left);
        inorder1.push_back(root->val);
        if(root->right)
            inorder(root->right);
    }
};