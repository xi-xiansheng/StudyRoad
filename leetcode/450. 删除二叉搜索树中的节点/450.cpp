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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur)
        {
            if (key < cur->val)
            {
                parent = cur;
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                parent = cur;
                cur = cur->right;
            }
            else
            {
                if (cur->left == nullptr)
                {
                    if (parent)
                    {
                        if (cur == parent->left)
                        {
                            parent->left = cur->right;
                            cur->right = nullptr;
                        }
                        else
                        {
                            parent->right = cur->right;
                            cur->right = nullptr;
                        }
                    }
                    else
                        root = root->right;
                }
                else if (cur->right == nullptr)
                {
                    if (parent)
                    {
                        if (cur == parent->left)
                        {
                            parent->left = cur->left;
                            cur->left = nullptr;
                        }
                        else
                        {
                            parent->right = cur->left;
                            cur->left = nullptr;
                        }
                    }
                    else
                        root = root->left;
                }
                else
                {
                    /*TreeNode* _left = cur->left;
                    TreeNode* _parent = cur;
                    while(_left && _left->right)
                    {
                        _parent = _left;
                        _left = _left->right;
                    }
                    cur->val = _left->val;
                    if(_parent-> left = _left)
                    {
                        _parent->left = _left->left;
                    }
                    else
                    {
                        _parent->right = _left->left;
                    }*/
                    TreeNode* MinRight = cur->right;
                    TreeNode* MinRightParent = cur;
                    while (MinRight && MinRight->left)
                    {
                        MinRightParent = MinRight;
                        MinRight = MinRight->left;
                    }
                    cur->val = MinRight->val;
                    if (MinRight == MinRightParent->right)
                        MinRightParent->right = MinRight->right;
                    else
                        MinRightParent->left = MinRight->right;
                }
                return root;
            }
        }
        return root;
    }
};