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
    TreeNode* _buildTree(vector<int>& preorder, const vector<int>& inorder)
    {
        int sz1 = preorder.size();
        int sz2 = inorder.size();
        if (sz1 == 0 || sz2 == 0)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = 0;
        while (mid < sz2 && inorder[mid] != preorder[0])
        {
            mid++;
        }
        preorder.erase(preorder.begin());
        vector<int> _inorderL;
        for (int i = 0; i < mid; i++)
        {
            _inorderL.push_back(inorder[i]);
        }
        vector<int> _inorderR;
        for (int i = mid + 1; i < sz2; i++)
        {
            _inorderR.push_back(inorder[i]);
        }
        root->left = _buildTree(preorder, _inorderL);
        root->right = _buildTree(preorder, _inorderR);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, inorder);
    }
};