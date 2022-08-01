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
        if (root == nullptr)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while (!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp)
            {
                ans += to_string(tmp->val);
                ans += ",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else
            {
                ans += "null,";
            }
        }
        int sz = ans.size();
        for (int i = sz - 1; i >= 0; i--)
        {
            if (ans[i] >= '0' && ans[i] <= '9')
            {
                sz = i;
                break;
            }
        }
        ans.resize(sz + 1);
        return ans;
    }

    // Decodes your encoded data to tree.
    string Leaf(const string& data, int& cur)
    {
        int start = cur;
        int sz = data.size();
        while (cur < sz && data[cur] != ',')
        {
            cur++;
        }
        return string(data.begin() + start, data.begin() + cur++);
    }

    TreeNode* deserialize(string data) {
        int sz = data.size();
        if (sz == 0)
            return nullptr;
        int cur = 0;
        TreeNode* root = new TreeNode(stoi(Leaf(data, cur)));
        queue<TreeNode*> q;
        q.push(root);
        while (cur < sz)
        {
            TreeNode* parent = q.front();
            string ret = Leaf(data, cur);
            if (ret != "null" && ret != "")
            {
                parent->left = new TreeNode(stoi(ret));
                q.push(parent->left);
            }
            ret = Leaf(data, cur);
            if (ret != "null" && ret != "")
            {
                parent->right = new TreeNode(stoi(ret));
                q.push(parent->right);
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));