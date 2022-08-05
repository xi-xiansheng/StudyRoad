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
    TreeNode* dfs(TreeNode* root, int curdepth, const int& val, const int& depth) {
        if (root == nullptr)
            return nullptr;
        if (curdepth == depth - 1)
        {
            TreeNode* _left = new TreeNode(val, root->left, nullptr);
            TreeNode* _right = new TreeNode(val, nullptr, root->right);
            root->left = _left;
            root->right = _right;
            return root;
        }
        dfs(root->left, curdepth + 1, val, depth);
        dfs(root->right, curdepth + 1, val, depth);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* _root = new TreeNode(val, root, nullptr);
            return _root;
        }
        dfs(root, 1, val, depth);
        return root;
    }
};