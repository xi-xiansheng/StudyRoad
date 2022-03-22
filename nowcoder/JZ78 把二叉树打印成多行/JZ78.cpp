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
    vector<vector<int> > vc;
    void Level_order(TreeNode* root)
    {
        if (root == nullptr)
            return;
        vector<int> vvc;
        queue<TreeNode*> qroot;
        qroot.push(root);
        //size 用以记录每层元素个数
        int size = 1;
        while (!qroot.empty())
        {
            //count 用来记录新增节点数目
            int count = 0;
            while (size)
            {
                //每层元素入vector，同时保存新一层节点
                if (qroot.front()->left)
                {
                    qroot.push(qroot.front()->left);
                    count++;
                }
                if (qroot.front()->right)
                {
                    qroot.push(qroot.front()->right);
                    count++;
                }
                vvc.push_back(qroot.front()->val);
                qroot.pop();
                size--;
            }
            //每层入一个二维数组
            vc.push_back(vvc);
            //置空，以保存新一层
            vvc.resize(0);
            //size 更新新一层节点数
            size += count;
        }
    }


    vector<vector<int> > Print(TreeNode* pRoot) {
        Level_order(pRoot);
        return vc;
    }

};