/**
Find parent of every node and store in a map.
Now from target node move in three directions simultaneously

Left side
Right side
Towards its parent side
Now when current_distance become equals to k we break out and our queue will store the ans.
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void assign(unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
             q.push(temp->left);
            mp[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                mp[temp->right]=temp;
            } 
        }
    return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        assign(mp,root);
        int dis=0;
        vector<int> ans;
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> curr;
        curr.push(target);
        vis[target]=true;
        while(!curr.empty()){
           if(dis==k)
           break;
        int size=curr.size();
        for(int i=0;i<size;i++){
            TreeNode* node=curr.front();
              curr.pop();
              if(node->left and vis[node->left]==false){
                 vis[node->left]=true;
                 curr.push(node->left);
                 }
            
            if(node->right and vis[node->right]==false){
                 vis[node->right]=true;
                 curr.push(node->right);
                 }
            if(mp[node]!=NULL and vis[mp[node]]==false){
               vis[mp[node]]=true;
                curr.push(mp[node]);
            }
        }
            dis++;
        }
        while(!curr.empty()){
            ans.push_back(curr.front()->val);
            curr.pop();
        }
    return ans;
    }
};