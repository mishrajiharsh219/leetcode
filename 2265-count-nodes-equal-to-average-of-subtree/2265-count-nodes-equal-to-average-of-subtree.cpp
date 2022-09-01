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
    int counter=0;
    int sumofsubtree(TreeNode*curr,int sum=0){
        if(curr->left==NULL and curr->right==NULL)
        {
            return curr->val;
        }
        if(curr->left){
        sum+=sumofsubtree(curr->left);
        }
        if(curr->right){
        sum+=sumofsubtree(curr->right);
        }
        return sum+curr->val;
    }
    
    
    
    int countofnodes(TreeNode* curr,int count=0){
         if(curr->left==NULL and curr->right==NULL)
        {
            return 1;
        }
        if(curr->left)
        count+=countofnodes(curr->left);
        if(curr->right)
        count+=countofnodes(curr->right);
        return count+1;
    }
    
    void dfs(TreeNode* curr){
        if(curr->left==NULL and curr->right==NULL)
        {
            counter++;
            return;
        }
        int sum=sumofsubtree(curr);
        int count=countofnodes(curr);
        if(sum/count==curr->val)
            counter++;
        if(curr->left)
            dfs(curr->left);
        if(curr->right)
            dfs(curr->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(!root->left and !root->right)
            return 1;
      dfs(root);
        return counter;
    }
};