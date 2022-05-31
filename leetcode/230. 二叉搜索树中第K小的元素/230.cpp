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
    void inorder(TreeNode* root, priority_queue<int, vector<int>>& q)
    {
        if (root == nullptr)
            return;
        inorder(root->left, q);
        if (q.size() < sz || root->val < q.top())
        {
            if (q.size() == sz)
                q.pop();
            q.push(root->val);
        }

        inorder(root->right, q);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>> q;
        sz = k;
        inorder(root, q);
        return q.top();
    }
private:
    int sz;
};