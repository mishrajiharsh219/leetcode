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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL)
            return -1;
        priority_queue<long long> pq;
        long long ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            long long temp=0;
            for(int i=0;i<n;i++)
            {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            temp+=node->val;
            }
            pq.push(temp);
        }
        if(pq.size()<k)
            return -1;
        k--;
        while(k--)
        {
          pq.pop();
        }
        return pq.top();
    }
};