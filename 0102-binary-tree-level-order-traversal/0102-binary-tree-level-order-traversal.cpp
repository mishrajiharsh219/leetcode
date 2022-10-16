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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
         return res;
        queue<TreeNode*> q;
       q.push(root);
        
        while(!q.empty()){
            int n=q.size();
             vector<int> crnt;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                crnt.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                q.pop();
            }
            res.push_back(crnt);
        }
        return res;
    }
};