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
    int SumTreeNodes(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return sum;
        if (root->left == nullptr)
            return SumTreeNodes(root->right, sum * 10 + root->val);
        if (root->right == nullptr)
            return SumTreeNodes(root->left, sum * 10 + root->val);
        return SumTreeNodes(root->left, sum * 10 + root->val) +
            SumTreeNodes(root->right, sum * 10 + root->val);
    }

    int sumNumbers(TreeNode* root) {
        return SumTreeNodes(root, 0);
    }
};