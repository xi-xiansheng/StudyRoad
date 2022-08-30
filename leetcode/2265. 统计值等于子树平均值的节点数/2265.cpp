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
    pair<int, int> dfs(TreeNode* root)
    {
        if (!root)   return make_pair(0, 0);
        auto lchild = dfs(root->left);
        auto rchild = dfs(root->right);
        auto cur = make_pair(lchild.first + rchild.first + root->val, lchild.second + rchild.second + 1);
        if (cur.first / cur.second == root->val) ans++;
        return cur;
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
private:
    int ans;
};