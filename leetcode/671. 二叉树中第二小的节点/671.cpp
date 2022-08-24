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
    void dfs(TreeNode* root)
    {
        if (!root)   return;
        if (ans != -1 && root->val >= ans)   return;
        if (root->val > cmp && (root->val < ans || ans == -1))
        {
            ans = root->val;
            return;
        }
        if (root->val == cmp)
        {
            dfs(root->left);
            dfs(root->right);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        cmp = root->val;
        dfs(root);
        return ans;
    }
private:
    int ans = -1;
    int cmp;
};