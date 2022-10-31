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
    int ans=INT_MAX;
    void preorder(TreeNode* root,vector<int> &res){
       if(root==NULL)
           return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        sort(res.begin(),res.end());
        for(int i=0;i<res.size()-1;i++){
            ans=min(ans,abs(res[i]-res[i+1]));
        }
        return ans;
    }
};