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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q1;
        queue<unsigned long long> q2;
        q2.push(0);
        q1.push(root);
        int ans = 1;
        while (!q1.empty())
        {
            int sz = q1.size();
            unsigned long long start = q2.front();
            while (sz--)
            {
                TreeNode* ret = q1.front();
                q1.pop();
                unsigned long long index = q2.front();
                q2.pop();
                if (ret->left)
                {
                    q1.push(ret->left);
                    q2.push(2 * index);
                }
                if (ret->right)
                {
                    q1.push(ret->right);
                    q2.push(2 * index + 1);
                }
                ans = std::max((unsigned long long)ans, index - start + 1);
            }
        }
        return (int)ans;
    }
};