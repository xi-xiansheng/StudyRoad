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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode* newroot = nullptr;
        TreeNode* SubLR = pRootOfTree->left;
        TreeNode* SubRL = pRootOfTree->right;

        //×ó×ÓÊ÷
        while (SubLR && SubLR->right)
        {
            SubLR = SubLR->right;
        }
        newroot = Convert(pRootOfTree->left);
        if (newroot == nullptr)
            newroot = pRootOfTree;
        if (SubLR)
            SubLR->right = pRootOfTree;
        pRootOfTree->left = SubLR;
        //ÓÒ×ÓÊ÷
        while (SubRL && SubRL->left)
        {
            SubRL = SubRL->left;
        }
        Convert(pRootOfTree->right);
        if (SubRL)
            SubRL->left = pRootOfTree;
        pRootOfTree->right = SubRL;

        return newroot;
    }
};