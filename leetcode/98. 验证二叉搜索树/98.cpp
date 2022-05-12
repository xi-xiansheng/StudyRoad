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
    void Inoder(TreeNode* root, vector<int>& vc)
    {
        if (root == nullptr)
            return;
        Inoder(root->left, vc);
        vc.push_back(root->val);
        Inoder(root->right, vc);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> vc;
        Inoder(root, vc);
        int sz = vc.size();
        for (int i = 0; i < sz - 1; i++)
        {
            if (vc[i] >= vc[i + 1])
                return false;
        }
        return true;
    }
};