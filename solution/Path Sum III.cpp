
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }

        int count = countFromNode(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }

    private:
    int countFromNode(TreeNode* node, long long targetSum){
        if(!node)
        return 0;

        int count = 0;

        if(node->val == targetSum){
            count++;
        }

        count += countFromNode(node->left, targetSum - node->val);
        count += countFromNode(node->right, targetSum - node->val);

        return count;

    }
};