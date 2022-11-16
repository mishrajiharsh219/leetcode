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
//BFS SOLUTION
//do the level order traversal for the deepest nodes
//since we will get 1 2 or more deeepest nodes 
//it is not possible for us to find lca of more than 2 nodes
//but lca of leftmost deepest node and rightmost deepest node is the lca of that subtree of deepest nodes
class Solution {
public:
    TreeNode* solve(TreeNode* root,TreeNode* left1,TreeNode* right1){
        if(root==NULL)
            return NULL;
        if(root==left1 or root==right1)
            return root;
        
        TreeNode* lefty=solve(root->left,left1,right1);
        TreeNode* righty=solve(root->right,left1,right1);
        
        if(lefty==NULL and righty==NULL)
            return NULL;
        else if(lefty==NULL)
            return righty;
        else if(righty==NULL)
            return lefty;
        
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      if(root==NULL)
          return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* leftest;
        TreeNode* rightest;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(i==0)
                    leftest=node;
                if(i==n-1)
                    rightest=node;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
      TreeNode* ans= solve(root,leftest,rightest);
      return ans;
    }
};