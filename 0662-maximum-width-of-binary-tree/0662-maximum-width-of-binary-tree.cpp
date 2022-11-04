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
    int widthOfBinaryTree(TreeNode* root) {
        int width=0;
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,long long unsigned int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                int curr_id=q.front().second-mini;
                if(i==0)
                    first=curr_id;
                if(i==n-1)
                    last=curr_id;
                TreeNode* node=q.front().first;
                q.pop();
                if(node->left){
                    q.push({node->left,(long long unsigned)2*curr_id+1});
                }
                  if(node->right){
                    q.push({node->right,(long long unsigned)2*curr_id+2});
                }
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};