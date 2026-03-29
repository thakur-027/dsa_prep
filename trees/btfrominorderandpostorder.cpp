/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int postIndex;

    int search(vector<int>& inorder, int start, int end, int target) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& inorder, 
    vector<int>& postorder, int inStart,int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = search(inorder, inStart, inEnd, rootVal);

        root->right = buildTree(inorder, postorder, inIndex + 1, inEnd);
        root->left = buildTree(inorder, postorder, inStart, inIndex - 1);
        

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        return buildTree(inorder, postorder, 0, inorder.size() - 1);
    }
};
