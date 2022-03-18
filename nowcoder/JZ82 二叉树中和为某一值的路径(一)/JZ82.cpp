/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if (root == nullptr)
            return false;
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
            return true;
        if (hasPathSum(root->left, sum - (root->val)))
            return true;
        if (hasPathSum(root->right, sum - (root->val)))
            return true;
        return false;
    }
};