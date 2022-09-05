/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
          if(root==NULL)
              return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int size=q.size();
            vector<int> currlevel;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                currlevel.push_back(temp->val);
                for(auto c:temp->children)
                    q.push(c);
            }
            res.push_back(currlevel);
        }
        return res;
    }
};