/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        /*if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;*/
        if (pRoot2 == nullptr || pRoot1 == nullptr)
            return false;
        if (pRoot1->val == pRoot2->val)
        {
            if (pRoot2->left == nullptr && pRoot2->right == nullptr)
                return true;
            else if (pRoot2->left == nullptr && pRoot2->right != nullptr)
                return HasSubtree(pRoot1->right, pRoot2->right);
            else if (pRoot2->left != nullptr && pRoot2->right == nullptr)
                return HasSubtree(pRoot1->left, pRoot2->left);
            if (HasSubtree(pRoot1->left, pRoot2->left) && HasSubtree(pRoot1->right, pRoot2->right))
                return true;
        }
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};