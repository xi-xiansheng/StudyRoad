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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vvc;
        vector<vector<TreeNode*>> vq;
        vector<TreeNode*> q;
        q.push_back(root);
        vq.push_back(q);
        q.pop_back();
        for (int i = 0; i < vq.size(); i++)
        {
            for (auto ee : vq[i])
            {
                if (ee->left)
                    q.push_back(ee->left);
                if (ee->right)
                    q.push_back(ee->right);
            }
            if (q.size() == 0)
                break;
            vq.push_back(q);
            q.clear();
        }
        vector<int> vc;
        for (auto e : vq)
        {
            for (auto ee : e)
            {
                vc.push_back(ee->val);
            }
            vvc.push_back(vc);
            vc.clear();
        }
        int sz = vvc.size();
        for (int i = 1; i < sz; i += 2)
        {
            int _left = 0;
            int _right = vvc[i].size() - 1;
            while (_left < _right)
            {
                std::swap(vvc[i][_left], vvc[i][_right]);
                _right--;
                _left++;
            }
        }
        return vvc;
    }
private:
    vector<vector<int>> vvc;
};