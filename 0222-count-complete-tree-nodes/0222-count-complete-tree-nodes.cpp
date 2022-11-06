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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=lefty(root);
        int rh=righty(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
    int lefty(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            if(node->left)
            node=node->left;
            else
                break;
        }
        return ans;
    }
     int righty(TreeNode* node){
        int ans=0;
        while(node){
            ans++;
            if(node->right)
            node=node->right;
            else
            break;
        }
        return ans;
     }
};