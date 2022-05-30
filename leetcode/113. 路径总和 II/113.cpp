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
    void PathFind(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && 0 == targetSum)
        {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        PathFind(root->left, targetSum);
        PathFind(root->right, targetSum);
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path.resize(0);
        paths.resize(0);
        PathFind(root, targetSum);
        return paths;
    }
private:
    vector<vector<int>> paths;
    vector<int> path;
};