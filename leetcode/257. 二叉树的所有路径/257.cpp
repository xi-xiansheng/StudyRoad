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
    void TreePath(TreeNode* root, string s)
    {
        s += to_string(root->val);
        s += "->";
        if (root->left)
            TreePath(root->left, s);
        if (root->right)
            TreePath(root->right, s);
        if (root->left == nullptr && root->right == nullptr)
        {
            if (s != "")
                s.resize(s.size() - 2);
            ans.push_back(s);
            return;
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr)
        {
            ans.push_back("");
            return ans;
        }
        TreePath(root, string());
        return ans;
    }
private:
    vector<string> ans;
};