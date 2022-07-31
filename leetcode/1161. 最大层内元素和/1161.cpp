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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, cur = 1;
        queue<TreeNode*> q;
        q.push(root);
        int maxsum = root->val;
        while (!q.empty())
        {
            int sz = q.size();
            int sum = 0;
            while (sz != 0)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                sum += tmp->val;
                sz--;
            }
            if (sum > maxsum)
            {
                maxsum = sum;
                ans = cur;
            }
            cur++;
        }
        return ans;
    }
};