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
    void Inorder(TreeNode* root, vector<TreeNode*>& vc)
    {
        if (root == nullptr)
            return;
        Inorder(root->left, vc);
        vc.push_back(root);
        Inorder(root->right, vc);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vc;
        Inorder(root, vc);
        int right = vc.size() - 1;
        int left = 0;
        while (left < right && vc[left]->val < vc[left + 1]->val)
        {
            left++;
        }
        while (left < right && vc[right]->val > vc[right - 1]->val)
        {
            right--;
        }
        int tmp = vc[left]->val;
        vc[left]->val = vc[right]->val;
        vc[right]->val = tmp;
    }
};