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
    void path(TreeNode* root, long long target)
    {
        if (root == nullptr)
            return;
        if ((long long)root->val == target)
            ans++;
        path(root->left, (long long)target - root->val);
        path(root->right, (long long)target - root->val);
    }

    int pathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return 0;
        path(root, target);
        pathSum(root->left, target);
        pathSum(root->right, target);
        return ans;
    }
private:
    int ans = 0;
};