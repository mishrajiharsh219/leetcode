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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
       bool leftToRight = true;
        while(!q.empty()){
            vector<int> t(q.size());
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode* temp=q.front();
                 q.pop();
                int index=leftToRight?i:n-i-1;
                t[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
              leftToRight=!leftToRight;
                res.push_back(t);
            
        }
        return res;
    }
};