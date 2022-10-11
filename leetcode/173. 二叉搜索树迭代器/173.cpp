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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        // µ¥µ÷Õ»
        dfs(root);
    }

    int next() {
        //return v[index++];
        TreeNode* ret = s.top();
        //int ret = q.front();
        //q.pop();
        s.pop();
        dfs(ret->right);
        return ret->val;
    }

    bool hasNext() {
        //return q.size() != 0;
        //return index < v.size();
        return s.size() != 0;
    }
private:
    void dfs(TreeNode* root)
    {
        if (!root)   return;
        s.push(root);
        dfs(root->left);
        //v.push_back(root->val);
        //q.push(root->val);
        //s.push(root);
        //dfs(root->right);
    }
    //int index = 0;
    //vector<int> v;
    //queue<int> q;
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */