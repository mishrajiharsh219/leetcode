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
//elk baar null aane ke baad koi element nahi aana chahiye
//agar null ,pre=false agar pre ke null hone ke baad koi element null nahi hai
//to return false;
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool pre=true;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                pre=false;
            }
            else {
                if(pre==false)
                    return pre;
                
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};