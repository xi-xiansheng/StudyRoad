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
    int PathSolve(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = PathSolve(root->left);
        int right = PathSolve(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        PathSolve(root);
        return ans;
    }
private:
    int ans = 0;
};