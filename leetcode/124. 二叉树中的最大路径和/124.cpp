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
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int _left = dfs(root->left);
        int _right = dfs(root->right);
        /*int max = std::max(0, std::max(_left, std::max(_right, _left + _right))) + root->val;
        if(max > ans)
            ans = max;
        return root->val + std::max(0, std::max(_left, _right));*/
        // 子树内部
        int InnerMax = _left + _right + root->val;
        ans = ans > InnerMax ? ans : InnerMax;
        // 对父节点
        int ToParent = root->val + std::max(_left, _right);
        return ToParent > 0 ? ToParent : 0;
    }


    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0x80000000;
};