class Solution {
public:
    
    TreeNode* constructTree(int s,int e,vector<int> &nums){
        if(s>e)
            return NULL;
        int idx=maxi(s,e,nums);
        TreeNode *root=new TreeNode(nums[idx]);
        root->left=constructTree(s,idx-1,nums);
        root->right=constructTree(idx+1,e,nums);
        return root;
    }
    
    
    int maxi(int i,int j,vector<int> &nums){
        int max=INT_MIN,index=-1;
       for(int s=i;s<=j;s++){
           if(nums[s]>max){
               max=nums[s];
       index=s;
       }}
        return index;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      int n=nums.size();
        TreeNode *root=constructTree(0,n-1,nums);
        return root;
    }
};