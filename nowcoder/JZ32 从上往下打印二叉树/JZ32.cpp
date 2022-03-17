/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        //≤„–Ú±È¿˙
        if (root == nullptr)
            return vector<int>();
        queue<TreeNode*> nodes;
        vector<int> vc;
        nodes.push(root);
        while (!nodes.empty())
        {
            vc.push_back(nodes.front()->val);
            if (nodes.front()->left)
                nodes.push(nodes.front()->left);
            if (nodes.front()->right)
                nodes.push(nodes.front()->right);
            nodes.pop();
        }
        return vc;
    }
};