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
    void dfs(TreeNode* root, int& _val)
    {
        if (root == nullptr)
            return;
        dfs(root->left, _val);
        ans = std::min(ans, root->val - _val);
        _val = root->val;
        dfs(root->right, _val);
    }

    int minDiffInBST(TreeNode* root) {
        int _val = -10000000;
        dfs(root, _val);
        return ans;
    }
private:
    int ans = 0x7fffffff;
};