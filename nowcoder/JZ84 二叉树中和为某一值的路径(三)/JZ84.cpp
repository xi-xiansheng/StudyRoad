/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型
     */
    int count = 0;
    void path(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return;
        if (root->val == sum)
            count++;
        path(root->left, sum - root->val);
        path(root->right, sum - root->val);
    }
    int FindPath(TreeNode* root, int sum) {
        // write code here
        if (root == nullptr)
            return 0;
        path(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);

        return count;
    }
};