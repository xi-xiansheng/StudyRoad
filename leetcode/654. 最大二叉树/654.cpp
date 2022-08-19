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
    TreeNode* dfs(vector<int>& v, int left, int right)
    {
        if (left > right)
            return nullptr;
        int idmax = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (v[idmax] < v[i])
                idmax = i;
        }
        TreeNode* root = new TreeNode(v[idmax]);
        root->left = dfs(v, left, idmax - 1);
        root->right = dfs(v, idmax + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};