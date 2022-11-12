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
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder,int &preindex,int start,int end){
        if(start>end or preindex>=preorder.size())
            return NULL;
        TreeNode* root=new TreeNode(preorder[preindex]);
        preindex++;
        if(preindex==preorder.size() or start==end)
            return root;
        int i;
        for(i=start;i<=end;i++){
            if(preorder[preindex]==postorder[i])
                break;
        }
        if(i<=end){
            root->left=helper(preorder,postorder,preindex,start,i);
            root->right=helper(preorder,postorder,preindex,i+1,end-1);
        }
        return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preindex=0;
        int start=0;
        int end=preorder.size()-1;
        return helper(preorder,postorder,preindex,start,end);
    }
};