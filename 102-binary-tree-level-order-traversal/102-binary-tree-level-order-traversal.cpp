
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL)
            return res;
        q.push(root);
        while(!q.empty()){
      int n=q.size();
            vector<int> crnt;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                crnt.push_back(curr->val);
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                q.pop();
            }
            res.push_back(crnt);
        }
        return res;
    }
};