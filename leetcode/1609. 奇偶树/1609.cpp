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
    bool isEvenOddTree(TreeNode* root) {
        int leval = 0;
        queue<TreeNode*> q;
        if (root != nullptr)
            q.push(root);
        while (!q.empty())
        {
            int sz = q.size() - 1;
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            int comp = cur->val;
            if (leval % 2 == 0)
            {
                if (cur->val % 2 == 0)
                    return false;
            }
            else
            {
                if (cur->val % 2 == 1)
                    return false;
            }
            while (sz != 0)
            {
                cur = q.front();
                q.pop();
                if (leval % 2 == 1)
                {
                    if (cur->val >= comp || cur->val % 2)
                        return false;
                }
                else
                {
                    if (cur->val <= comp || cur->val % 2 == 0)
                        return false;
                }
                comp = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                sz--;
            }
            leval++;
        }
        return true;
    }
};