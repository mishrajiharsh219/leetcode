// In-order traversal of BST yields sorted sequence. So, we just need to subtract the previous element from the current one, and keep track of the minimum. We need O(1) memory as we only store the previous element, but we still need O(h) for the stack.
class Solution {
public:
   int inorderTraverse(TreeNode* root, int& val, int& min_dif) {
    if (root->left != NULL)
        inorderTraverse(root->left, val, min_dif);
    if (val >= 0) 
        min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) 
        inorderTraverse(root->right, val, min_dif);
    return min_dif;
}
int getMinimumDifference(TreeNode* root) {
    auto min_dif = INT_MAX, val = -1;
    return inorderTraverse(root, val, min_dif);
}
};