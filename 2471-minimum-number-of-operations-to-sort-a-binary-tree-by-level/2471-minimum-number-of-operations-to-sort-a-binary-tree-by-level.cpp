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
      int oper=0;
    void minswaps(vector<int> &v){
        map<int,int> mp;
         for(int i=0;i<v.size();i++){
         mp[v[i]]=i;
         }
        vector<int> temp(v.begin(),v.end());
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(v[i]!=temp[i]){
                int k=mp[temp[i]];
                int l=mp[v[i]];
                mp[v[i]]=k;
                mp[temp[i]]=l;
                swap(v[i],v[k]);
                
                oper++; 
            }
        }
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> level;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int> ans;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                ans.push_back(temp->val);
            }
            level.push_back(ans);
        }
      for(auto v:level){
      minswaps(v);
      }
        
        return oper;
    }
};