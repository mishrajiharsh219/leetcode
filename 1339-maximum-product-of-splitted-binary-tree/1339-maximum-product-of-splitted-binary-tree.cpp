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
    long long max(long long a,long long b){
        if(a>b)
            return a;
        return b;
    }
   long long int totalsum=0;
   long long maxi=0;
    int mod=1e9+7;
    void totalsumfunc(TreeNode* root){
        if(root){
            totalsum+=root->val;
            totalsumfunc(root->left);
            totalsumfunc(root->right);
        }
        return;
    }
    long long int dfs(TreeNode* root){
       
        if(root==NULL)
            return 0;
        long long int left= dfs(root->left);
        long long int right=dfs(root->right);
        
        long long int currsum=left+right+root->val;
        long long int seperate=totalsum-currsum;
        long long prod=(currsum*seperate);
        maxi=max(maxi,prod);
        
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        totalsumfunc(root);
        long long int newsum=dfs(root);
        return maxi%mod;
    }
};