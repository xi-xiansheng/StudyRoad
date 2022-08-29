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
    vector<int> dfs(TreeNode* root)
    {
        if (!root)   return vector<int>();
        if (root->left == nullptr && root->right == nullptr) return vector<int>(1, 0);
        vector<int> _l = dfs(root->left);
        vector<int> _r = dfs(root->right);
        for (auto& l : _l)
        {
            l += 1;
        }
        for (auto& r : _r)
        {
            r += 1;
        }
        for (auto& r : _r)
        {
            for (auto& l : _l)
            {
                if (l + r <= dis)    ans++;
            }
        }
        //ÕûºÏ
        for (auto& r : _r)
        {
            _l.push_back(r);
        }

        return _l;
    }

    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        dis = distance;
        dfs(root);
        return ans;
    }
private:
    int dis;
    int ans;
};