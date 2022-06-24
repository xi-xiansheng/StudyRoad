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
    vector<int> largestValues(TreeNode* root)
    {
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int max = q.front()->val;
            int sz = q.size();
            while (sz--)
            {
                TreeNode* res = q.front();
                q.pop();
                if (max < res->val)
                    max = res->val;
                if (res->left)
                    q.push(res->left);
                if (res->right)
                    q.push(res->right);
            }
            ans.push_back(max);
        }
        return ans;
    }
private:
    vector<int> ans;
};