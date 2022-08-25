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
    int dfs(Node* root)
    {
        if (!root)   return 0;
        int maxdepth = 0;
        for (auto& children_ : root->children)
        {
            maxdepth = std::max(maxdepth, dfs(children_));
        }
        return 1 + maxdepth;
    }
    int maxDepth(Node* root) {
        return dfs(root);
    }
};