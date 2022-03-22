/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<vector<int>> allpath;

    void order(TreeNode* root, vector<int>& path, int expectNumber)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        if (expectNumber == root->val && (root->left == nullptr || root->right == nullptr))
            allpath.push_back(path);
        order(root->left, path, expectNumber - (root->val));
        order(root->right, path, expectNumber - (root->val));
        path.pop_back();
    }

    vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
        vector<int> path;
        order(root, path, expectNumber);

        return allpath;
    }
};