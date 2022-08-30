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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> s;
        for (auto& d : descriptions)
        {
            if (m.count(d[0]) == 0)
            {
                m[d[0]] = new TreeNode(d[0]);
            }
            if (m.count(d[1]) == 0)
            {
                m[d[1]] = new TreeNode(d[1]);
            }
            if (d[2] == 1)
                m[d[0]]->left = m[d[1]];
            else
                m[d[0]]->right = m[d[1]];
            if (s.count(d[0]) == 0)
            {
                s[d[0]] = true;
            }
            s[d[1]] = false;
        }
        TreeNode* root = nullptr;
        for (auto& [k, v] : s)
        {
            if (v)
            {
                root = m[k];
                break;
            }
        }
        return root;
    }
};