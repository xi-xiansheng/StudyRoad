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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> m;
        if (root)    q.push(make_pair(root, 0));
        while (!q.empty())
        {
            int sz = q.size();
            map<int, vector<int>> ret;
            while (sz--)
            {
                auto f = q.front();
                q.pop();
                ret[f.second].push_back(f.first->val);
                if (f.first->left)   q.push(make_pair(f.first->left, f.second - 1));
                if (f.first->right)   q.push(make_pair(f.first->right, f.second + 1));
            }
            for (auto& [k, v] : ret)
            {
                std::sort(v.begin(), v.end());
            }
            for (auto& [k, v] : ret)
            {
                for (auto& e : v)
                {
                    m[k].push_back(e);
                }
            }
        }
        for (auto& [k, v] : m)
        {
            ans.push_back(v);
        }
        return ans;
    }
};