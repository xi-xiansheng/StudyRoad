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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            double dividend = (double)sz;
            double sum = 0;
            while (sz--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                sum += tmp->val;
            }
            ans.push_back(sum / dividend);
        }
        return ans;
    }
};