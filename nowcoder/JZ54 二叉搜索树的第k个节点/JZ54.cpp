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
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */

    int number(TreeNode* proot, int& n, int k)
    {
        if (proot == nullptr)
        {
            return -1;
        }
        int num = number(proot->left, n, k);
        if (num != -1)
            return num;
        n++;
        if (n == k)
            return proot->val;
        num = number(proot->right, n, k);
        return num;
    }

    int KthNode(TreeNode* proot, int k) {
        // write code here
        int n = 0;
        return number(proot, n, k);
    }
};