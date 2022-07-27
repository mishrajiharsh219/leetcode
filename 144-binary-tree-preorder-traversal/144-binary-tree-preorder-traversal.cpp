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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(root==NULL)
            return pre;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr= st.top();
            pre.push_back(curr->val);
            st.pop();
            
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!= NULL)
                 st.push(curr->left);
        }
        return pre;
    }
};










