
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;

        int maximumSum = INT_MIN;//initializing with the smallest possible integer value
        int resultLevel = 0;

        queue<TreeNode*> q;
        q.push(root);

        int currentLevel = 1;

        while(!q.empty()){
     
        int n = q.size();

        int sum = 0;


        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();

            sum += temp->val;

           if(temp->left) q.push(temp->left);
           if(temp->right) q.push(temp->right);

        }

        if(sum > maximumSum){
            maximumSum = sum;
            resultLevel = currentLevel;
        }

        currentLevel++;
     }

     return resultLevel;

   } 
};