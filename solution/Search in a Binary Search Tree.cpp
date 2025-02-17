class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            //In binary search tree, if the value is greater than the root? we search the right subtree else left
            if(val > root->val){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return root;

    }
};