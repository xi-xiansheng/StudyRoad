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
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    TreeNode* dfs(TreeNode* root, int o1, int o2) {
        if (root == nullptr) return nullptr;
        if (root->val == o1 || root->val == o2) return root;
        TreeNode* t1 = dfs(root->left, o1, o2);
        TreeNode* t2 = dfs(root->right, o1, o2);
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        return root;
    }


    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here

        return dfs(root, o1, o2)->val;
    }
};