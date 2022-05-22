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
    void node_push(TreeNode* root, vector<TreeNode*>& v)
    {
        if (root == nullptr)
            return;
        v.push_back(root);
        node_push(root->left, v);
        node_push(root->right, v);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        node_push(root, v);
        int sz = v.size();
        for (int i = 0; i < sz - 1; i++)
        {
            v[i]->right = v[i + 1];
            v[i]->left = nullptr;
        }
    }
};