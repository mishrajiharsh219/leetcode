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
    TreeNode* helper(int s,int e,vector<int> &nums){
        int idx=maxi(s,e,nums);
       if(s>e)
           return NULL;
        TreeNode *root=new TreeNode(nums[idx]);
        root->left=helper(s,idx-1,nums);
        root->right=helper(idx+1,e,nums);
        return root;
    }
    
    int maxi(int i,int j,vector<int> &nums){
        int indx=-1,m=INT_MIN;
        for(int a=i;a<=j;a++){
            if(nums[a]>m){
                m=nums[a];
                indx=a;
            }
        }
            return indx;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root=helper(0,n-1,nums);
        return root;
    }
};