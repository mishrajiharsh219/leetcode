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
   for(auto x: mp){
            cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<" ";
            cout<<endl;
        }
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root,unordered_map<int,pair<int,int>> &mp,int i){
         if(mp.find(root->val)==mp.end())
             return NULL;
        TreeNode* node;
        if(mp.find(root->val)!=mp.end()){
            if(i==0)
            { node=new TreeNode(mp[root->val].first);
            }
            else{
             node=new TreeNode(mp[root->val].second); 
            }
        }
        if(node->val==0)
            return NULL;
        node->left=dfs(node,mp,0);
        node->right=dfs(node,mp,1);
        
        
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>> mp;
        set<int> childs;
        for(int i=0;i<descriptions.size();i++){
                if(descriptions[i][2]==1){
                mp[descriptions[i][0]].first=descriptions[i][1];
                }
                else if(descriptions[i][2]==0){
                 mp[descriptions[i][0]].second=descriptions[i][1];
                }
        }
        for(int i=0;i<descriptions.size();i++){
            childs.insert(descriptions[i][1]);
        }
      for(int i=0;i<descriptions.size();i++){
            childs.insert(descriptions[i][1]);
        }
        int parent=0;
       for(int i=0;i<descriptions.size();i++){
         if(childs.find(descriptions[i][0])==childs.end())
             parent=descriptions[i][0];
        } 
        TreeNode* root=new TreeNode(parent);
        root->left=dfs(root,mp,0);
        root->right=dfs(root,mp,1);
      
        return root;
    }
};