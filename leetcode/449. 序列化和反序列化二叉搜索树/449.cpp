/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (root == nullptr)
            return s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            if (tmp)
            {
                s += to_string(tmp->val);
                q.push(tmp->left);
                q.push(tmp->right);
            }
            s += ' ';
            q.pop();
        }
        return s;
    }
    TreeNode* TreeBuilt(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if (val < root->val)
            root->left = TreeBuilt(root->left, val);
        else
            root->right = TreeBuilt(root->right, val);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;
        queue<TreeNode*> q;
        char* cstr = (char*)data.c_str();
        const char* re = " ";
        TreeNode* root = new TreeNode(atoi(strtok(cstr, re)));
        q.push(root);
        while ((cstr = strtok(NULL, re)) != NULL)
        {
            int _val = atoi(cstr);
            TreeBuilt(root, _val);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;