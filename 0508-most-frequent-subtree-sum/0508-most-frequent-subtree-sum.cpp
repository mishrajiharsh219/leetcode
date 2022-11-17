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
    map<int,int> mp;
    
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
       int leftsum= dfs(root->left);
       int rightsum=dfs(root->right);
       
        int sum=leftsum+rightsum+root->val;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> ans;
        vector<int> temp;
        int sumroot=dfs(root);
        int frq=0;
        for(auto x:mp)
        {
            if(x.second>frq){
                frq=x.second;
                ans.clear();
                ans.push_back(x.first);
            }
            else if(x.second==frq){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};