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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz1 = postorder.size();
        int sz2 = inorder.size();
        if (sz1 == 0 || sz2 == 0)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[sz1 - 1]);
        int mid = 0;
        while (mid < sz2 && inorder[mid] != postorder[sz1 - 1])
        {
            mid++;
        }
        postorder.pop_back();
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
        root->right = buildTree(_inorderR, postorder);
        root->left = buildTree(_inorderL, postorder);
        return root;
    }
};