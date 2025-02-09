
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val or root->val == q->val){
            return root;
        }

        if(!root->left and !root->right){
            return NULL;
        }

        TreeNode *left=NULL, *right=NULL;
//go depth to the left of the root
        if(root->left){
            left = lowestCommonAncestor(root->left, p, q);
        }
//go right to the depth of the node
        if(root->right){
            right = lowestCommonAncestor(root->right, p, q);
        }
        if(left and right){
            return root;
        }
        return left == NULL ? right : left;
    }
};