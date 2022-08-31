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
    int dfs(TreeNode* root, int arr[2])
    {
        if (!root)   return -1;
        int arr1[2] = { std::max(arr[0], root->val), std::min(arr[1], root->val) };
        int ans = std::max(abs(root->val - arr[0]), abs(arr[1] - root->val));
        ans = std::max(ans, std::max(dfs(root->left, arr1), dfs(root->right, arr1)));
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        int arr[2] = { root->val, root->val };
        return dfs(root, arr);
    }
};