/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(root==NULL){return "";}
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                str.append("#,");
            }
            else
            {
                str.append(to_string(curr->val)+',');
            }
           if(curr!=NULL)
           {
               q.push(curr->left);
               q.push(curr->right);
           }
        }
       return str; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size()==0)
           return NULL;
        string s;
        stringstream ss(data);
        getline(ss,s,',');
        TreeNode* root=new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            string s;
            getline(ss,s,',');
            if(s=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* lefty=new TreeNode(stoi(s));
                node->left=lefty;
                q.push(lefty);
            }
             string st;
            getline(ss,st,',');
            if(st=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* righty=new TreeNode(stoi(st));
                node->right=righty;
                q.push(righty);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));