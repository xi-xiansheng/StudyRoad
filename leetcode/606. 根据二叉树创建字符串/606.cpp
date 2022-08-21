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
    bool preorder(TreeNode* root, string& s)
    {
        if (root == nullptr)
        {
            return false;
        }
        s += to_string(root->val) + "(";
        bool flag1 = preorder(root->left, s);
        s += ")(";
        bool flag2 = preorder(root->right, s);
        s += ")";
        if (flag1 == false && flag2 == false)
        {
            for (int i = 0; i < 4; i++)
                s.pop_back();
        }
        else if (flag1 && flag2 == false)
        {
            s.pop_back();
            s.pop_back();
        }
        return true;
    }
    string tree2str(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }
};