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
    int postindex;
    unordered_map<int,int> mp;
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder,int start,int end){
        
        if(start>end){
            return NULL;
        }
        int inindex=mp[postorder[postindex--]];
        TreeNode* root=new TreeNode(inorder[inindex]);
        
        root->right=construct(inorder,postorder,inindex+1,end);
        root->left=construct(inorder,postorder,start,inindex-1);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postindex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return construct(inorder,postorder,0,inorder.size()-1);
    }
};