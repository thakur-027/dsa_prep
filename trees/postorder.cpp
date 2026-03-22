class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        inorder(root->left, ans);
        inorder(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
