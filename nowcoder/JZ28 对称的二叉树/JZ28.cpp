/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool symmetrical(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr && right != nullptr)
            return false;
        if (left != nullptr && right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return symmetrical(left->left, right->right) &&
            symmetrical(left->right, right->left);
    }

    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return true;
        return symmetrical(pRoot->left, pRoot->right);
    }
};