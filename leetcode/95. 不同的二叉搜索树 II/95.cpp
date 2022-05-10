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
    TreeNode* TreeBulit(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode* node = new TreeNode(root->val);
        node->left = TreeBulit(root->left);
        node->right = TreeBulit(root->right);
        return node;
    }

    void Add(TreeNode* root, int n)
    {
        if (root == nullptr)
            return;
        root->val += n;
        Add(root->left, n);
        Add(root->right, n);
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> vc(n + 1);
        vc[0] = { nullptr };
        for (int index = 1; index <= n; index++)
        {
            int left = 0;
            int right = 0;
            for (int i = 1; i <= index; i++)
            {
                left = i - 1;
                right = index - i;
                for (auto _left : vc[left])
                {
                    for (auto _right : vc[right])
                    {
                        TreeNode* node = new TreeNode(i);
                        node->left = TreeBulit(_left);
                        node->right = TreeBulit(_right);
                        Add(node->right, i);
                        vc[index].push_back(node);
                    }
                }
            }
        }
        return vc[n];
    }
};