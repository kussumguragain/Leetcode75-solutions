class Solution {
public:
    int countGoodNodes(TreeNode* root, int curMax) {
        if (!root) return 0; // if node is null, return 0

        int count = 0;
        if (root->val >= curMax) { // Checking if the node is a "good node"
            count = 1; 
            curMax = root->val; // Update max value seen
        }

        // Recursively check left and right subtrees
        count += countGoodNodes(root->left, curMax);
        count += countGoodNodes(root->right, curMax);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val); // Start with root's value as curMax
    }
};