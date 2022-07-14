//the first element of a preorder is always root
//search that root in inorder and all element to the left of that root in inorder will be
//left subtree ,and all elements to right of that root in inorder will be of right subtree
//this will happen recursively
//only one possible solution for every input
//The tree is constructed in a recrusive depth-first manner. two seperate recursive calls are made for left and right subtree respectively.
//At each recursive call we only look at nodes that are potential candidates for later subtrees.
// When we go the left, we only want nodes from both inorder and preorder that reside in the left subtree. same for when we go to the right.
class Solution {
public:
    int preind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder,inorder,0,preorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder,int start,int end){
         if(start>end){
           return NULL;
       }  

        TreeNode* node=new TreeNode(preorder[preind++]);
                int pos;
        for(int i=start;i<=end;i++ ){
            if(inorder[i]==node->val){
                pos=i;
                break;
            }
        }
        node->left=create(preorder,inorder,start,pos-1);
        node->right=create(preorder,inorder,pos+1,end);
    return node;
    }
};


