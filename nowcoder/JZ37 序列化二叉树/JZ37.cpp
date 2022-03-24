/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:

    string s;
    char* Serialize(TreeNode* root)
    {
        //层序遍历
        if (root == nullptr)
        {
            return "#";
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            if (root)
            {
                q.push(root->left);
                q.push(root->right);
            }
            if (root == nullptr)
                s += '#';
            else
                s += '0' + root->val - 128;
            q.pop();
        }
        char* src = new char[s.size()];
        strcpy(src, s.c_str());
        return src;
    }

    TreeNode* Deserialize(char* str) {
        if (str == nullptr || *str == '\0' || *str == '#')
            return nullptr;
        TreeNode* root = new TreeNode(*str - '0' + 128);
        TreeNode* head = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && str && *str != '\0')
        {
            //找到不为空的节点
            str++;
            while (!q.empty() && q.front() == nullptr)
            {
                q.pop();
            }
            if (q.empty())
                break;
            root = q.front();
            //左孩子
            if (str == nullptr || *str == '\0' || *str == '#')
                root->left = nullptr;
            else
                root->left = new TreeNode(*str - '0' + 128);
            q.push(root->left);
            //右孩子
            str++;
            if (str == nullptr || *str == '\0' || *str == '#')
                root->right = nullptr;
            else
                root->right = new TreeNode(*str - '0' + 128);
            q.push(root->right);
            q.pop();
        }
        return head;
    }
};