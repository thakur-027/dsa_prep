class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // If we reach a leaf node, return the current depth
                if (!node->left && !node->right) {
                    return depth;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};
