class Solution {
public:

    void getLeaves(TreeNode* root, string& leaves){
        if(!root)
        return;

        if(!root->left && !root->right){
            leaves += to_string(root->val) + ",";
        }

        getLeaves(root->left, leaves);//goes deep to the left subtree
        getLeaves(root->right, leaves);//visits the right subtree
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return(leaves1 == leaves2);
    }
};