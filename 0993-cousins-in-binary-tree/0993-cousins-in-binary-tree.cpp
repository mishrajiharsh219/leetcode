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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        bool marker=true;
        while(!q.empty() and marker)
        {
            int n =q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
  if(((temp->left and temp->left->val==x) or (temp->right and temp->right->val==x) or (temp->left and temp->left->val==y) or (temp->right and temp->right->val==y)) and marker==false)
      return true;
 if(((temp->left and temp->left->val==x) or (temp->right and temp->right->val==x) or (temp->left and temp->left->val==y) or (temp->right and temp->right->val==y)) and marker==true)
                    marker=false;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return false;
    }
};