class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;  // If the tree is empty, return an empty result.

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level
            int rightmostValue;  // Store the last node value at this level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                rightmostValue = node->val;  // We update last node at this level

                if (node->left) q.push(node->left);  // Push left child of the current node
                if (node->right) q.push(node->right);  // Push right child of the current node
            }

            result.push_back(rightmostValue);  // Add the rightmost node of this level
        }

        return result;
    }
};