/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* _left = nullptr;
        TreeLinkNode* _right = nullptr;

        if (pNode->right == nullptr)
        {
            while (pNode && pNode->next)
            {
                if (pNode == pNode->next->right)
                    pNode = pNode->next;
                else
                    break;
            }
            if (pNode->next && pNode == pNode->next->left)
                return pNode->next;
            if (pNode->next == nullptr)
                return nullptr;
        }

        _right = pNode->right;
        _left = _right;

        while (_left && _left->left)
        {
            _left = _left->left;
        }

        return _left;
    }
};