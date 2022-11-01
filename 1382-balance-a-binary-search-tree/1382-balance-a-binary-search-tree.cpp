/**
1. 	Create a vector Inorder to store the nodes. 
	
	2. 	Traverse the tree in such a way that the nodes stored in the vector are in ascending order i.e. Inorder Traversal. 
								Inorder: [ 1, 2, 3, 4 ]
								
	3. 	Then use this vector of nodes to find the root node of the balanced BST.
	
	4. 	The newRoot node will be mid element of the array;
								newRoot= Inorder[mid]=2
								
	5. Then recursively add the mid of first half to the left of the tree.
								newRoot->left=1
								
	6. And the mid of second half to the right of the tree.
								newRoot->right=3
 */
class Solution {
public:
      vector<int> inorder;
    void sorted(TreeNode* root,vector<int> &inorder){
        if(root){
         if(root->left)sorted(root->left,inorder);
         inorder.push_back(root->val);   
        if(root->right)sorted(root->right,inorder);
        }
    }
    TreeNode* buildtree(int l,int r){
        if(l>r)
            return NULL;
        TreeNode* node=new TreeNode();
        int mid=l+(r-l)/2;
        node->val=inorder[mid];
        node->left=buildtree(l,mid-1);
        node->right=buildtree(mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        sorted(root,inorder);
        int n=inorder.size();
        root=buildtree(0,n-1);
        return root;
    }
};