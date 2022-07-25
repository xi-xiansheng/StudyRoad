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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        if (root == nullptr)
            return;
        queue<TreeNode*> _q;
        _q.push(root);
        while (!_q.empty())
        {
            TreeNode* cur = _q.front();
            insert(cur->val);
            _q.pop();
            if (cur->left)
                _q.push(cur->left);
            if (cur->right)
                _q.push(cur->right);
        }
    }

    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        if (q.empty())
        {
            _root = node;
            q.push(node);
            return 0;
        }
        TreeNode* root = q.front();
        q.push(node);
        if (root->left == nullptr)
            root->left = node;
        else
        {
            root->right = node;
            q.pop();
        }
        return root->val;
    }

    TreeNode* get_root() {
        return _root;
    }
private:
    queue<TreeNode*> q;
    TreeNode* _root = nullptr;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */