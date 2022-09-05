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
    int dfs(TreeNode* root, int depth)
    {
        if (!root)
        {
            maxdepth = std::max(maxdepth, depth);
            return depth;
        }
        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);
        if (left == right && left == maxdepth)  ans = root;
        return std::max(left, right);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ans = nullptr;
        maxdepth = 0;
        dfs(root, 0);
        return ans;
    }
private:
    TreeNode* ans;
    int maxdepth;
};