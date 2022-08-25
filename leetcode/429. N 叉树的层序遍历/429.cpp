/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if (root)    q.push(root);
        while (!q.empty())
        {
            vector<int> ret;
            int sz = q.size();
            while (sz--)
            {
                Node* cur = q.front();
                q.pop();
                for (auto& children_ : cur->children)
                {
                    q.push(children_);
                }
                ret.push_back(cur->val);
            }
            ans.push_back(ret);
        }
        return ans;
    }
};