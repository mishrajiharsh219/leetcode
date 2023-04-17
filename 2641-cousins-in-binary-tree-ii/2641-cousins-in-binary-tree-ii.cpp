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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            root->val=0;
            return root;
        }
        root->val=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> buff;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            buff.clear();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                buff.push_back(temp);
                if(temp->left)
                {
                    q.push(temp->left);
                    sum+=temp->left->val;
                }
                 if(temp->right)
                {
                    q.push(temp->right);
                    sum+=temp->right->val;
                }
            }
            for(auto node:buff)
            {
                int temp=int(sum);
                if(node->left)
                {
                    temp=temp-node->left->val;
                }
                if(node->right)
                {
                    temp=temp-node->right->val;
                }
                if(node->left)
                {
                    node->left->val=temp;
                }
                if(node->right)
                {
                    node->right->val=temp;
                }
            }
            
        }
        return root;
    }
};