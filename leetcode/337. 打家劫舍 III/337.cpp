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
    unordered_map<TreeNode*, int> _rob, _unrob;
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        _rob[root] = root->val + _unrob[root->left] + _unrob[root->right];
        _unrob[root] = std::max(_rob[root->left], _unrob[root->left]) +
            std::max(_rob[root->right], _unrob[root->right]);
    }
    int rob(TreeNode* root)
    {
        dfs(root);
        return std::max(_rob[root], _unrob[root]);
    }
};