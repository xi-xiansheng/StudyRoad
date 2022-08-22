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
    void dfs1(TreeNode* root, int depth)
    {
        if (root == nullptr)
        {
            maxdepth = std::max(maxdepth, depth);
            return;
        }
        dfs1(root->left, depth + 1);
        dfs1(root->right, depth + 1);
    }
    void dfs2(TreeNode* root, int depth, int left, int right)
    {
        if (root == nullptr)
            return;
        int mid = (left + right) / 2;
        dfs2(root->left, depth + 1, left, mid - 1);
        dfs2(root->right, depth + 1, mid + 1, right);
        ans[depth][mid] = to_string(root->val);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        maxdepth = 0;
        dfs1(root, 0);
        ans.resize(maxdepth, vector<string>(pow(2, maxdepth) - 1));
        dfs2(root, 0, 0, pow(2, maxdepth) - 1);
        return ans;
    }
private:
    vector<vector<string>> ans;
    int maxdepth;
};