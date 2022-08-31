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
    pair<TreeNode*, int> dfs(TreeNode* root, int depth)
    {
        if (!root)   return make_pair(nullptr, depth - 1);
        if (root->left == nullptr && root->right == nullptr) return make_pair(root, depth);
        auto l = dfs(root->left, depth + 1);
        auto r = dfs(root->right, depth + 1);
        pair<TreeNode*, int> ans;
        if (l.second == r.second)
            ans = make_pair(root, l.second);
        else if (l.second > r.second)
            ans = make_pair(l.first, l.second);
        else
            ans = make_pair(r.first, r.second);
        return ans;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).first;
    }
};