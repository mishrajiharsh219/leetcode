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
       
        while(!q.empty()){
            vector<int> t;
            int n=q.size();
            for(int i=0;i<n;i++){
                 TreeNode* temp=q.front();
                 q.pop();
                t.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(res.size()%2==0)
            res.push_back(t);
            else
            {
                reverse(t.begin(),t.end());
                res.push_back(t);
            }
        }
        return res;
    }
};