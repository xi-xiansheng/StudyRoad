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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        int ans = sumOfLeftLeaves(root->right);
        while (root->left)
        {
            root = root->left;
            ans += sumOfLeftLeaves(root->right);
        }
        ans += root->right == nullptr ? root->val : 0;
        return ans;
    }
};