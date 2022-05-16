/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void order(TreeNode* root)
    {
        if (root == nullptr)
            return;
        order(root->left);
        v.push_back(root);
        order(root->right);
    }

    int BinaSearch(TreeNode* p)
    {
        int left = 0;
        int right = v.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (v[mid]->val > p->val)
                right = mid - 1;
            else if (v[mid]->val < p->val)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        v.resize(0);
        order(root);
        int index = BinaSearch(p);
        if (index == v.size() - 1 || index == -1)
            return nullptr;
        return v[index + 1];
    }
private:
    vector<TreeNode*> v;
};