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
    string dfs(TreeNode* root)
    {
        if (root == nullptr)
            return "#";
        string s = to_string(root->val) + "#";
        s += dfs(root->left);
        s += dfs(root->right);
        m[s] += 1;
        if (m[s] == 2)
            ans.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    map<string, int> m;
    vector<TreeNode*> ans;
};