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
    void dfs(TreeNode* root, int depth)
    {
        if (root == nullptr)
            return;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
        if (maxdepth < depth)
            ans = root->val;
        else if (maxdepth == depth)
            ans += root->val;
        maxdepth = std::max(depth, maxdepth);
    }

    int deepestLeavesSum(TreeNode* root) {
        ans = maxdepth = 0;
        dfs(root, 0);
        return ans;
    }
private:
    int ans = 0;
    int maxdepth = 0;
};