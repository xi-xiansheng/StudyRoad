/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        /*queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz)
            {
                Node* cur = q.front();
                q.pop();
                if(sz == 1)
                    cur->next = nullptr;
                else
                    cur->next = q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                sz--;
            }
        }*/

        // ³£Á¿¸¨Öú¿Õ¼ä
        Node* first = nullptr;
        Node* cur = root;
        while (cur)
        {
            Node* _cur = nullptr;
            while (cur)
            {
                if (cur->left)
                {
                    if (_cur == nullptr)
                        _cur = first = cur->left;
                    else
                    {
                        _cur->next = cur->left;
                        _cur = _cur->next;
                    }
                }
                if (cur->right)
                {
                    if (_cur == nullptr)
                        _cur = first = cur->right;
                    else
                    {
                        _cur->next = cur->right;
                        _cur = _cur->next;
                    }
                }
                cur = cur->next;
            }
            cur = first;
            first = nullptr;
        }
        return root;
    }
};