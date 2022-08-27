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
    int dfs(TreeNode* root, int cmp = -1, int depth = 0)
    {
        if (!root)   return 0;
        int left_ = dfs(root->left, root->val, depth);
        int right_ = dfs(root->right, root->val, depth);
        maxdepth = std::max(maxdepth, left_ + right_);
        return root->val != cmp ? 0 : 1 + std::max(left_, right_);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxdepth;
    }
private:
    int maxdepth = 0;
};