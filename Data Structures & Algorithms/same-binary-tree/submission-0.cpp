class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q;
        q.push(root1);
        q.push(root2);

        // Loop till the queue is not empty
        while (!q.empty()) {
            TreeNode* first = q.front(); q.pop();
            TreeNode* second = q.front(); q.pop();

            // Check for equality
            if (first == nullptr && second == nullptr) {
                continue;
            } else if (first == nullptr || second == nullptr || first->val != second->val) {
                return false;
            }

            // Add other nodes
            q.push(first->left);
            q.push(second->left);
            q.push(first->right);
            q.push(second->right);
        }

        return true;
    }
};