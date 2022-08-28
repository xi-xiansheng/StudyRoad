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
 /*class Solution {
 public:
     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         if(preorder.size() == 0)    return nullptr;
         TreeNode* root = new TreeNode(preorder[0]);
         int count = 0, RightIntval = 0;
         map<int, int> m;
         for(int i = 0, sz = preorder.size(); i + 1 < sz; i++)
         {
             m[preorder[i + 1]] += 1;
             if(m[preorder[i + 1]])  count++;
             else    count--;
             m[postorder[i]] -= 1;
             if(m[postorder[i]]) count++;
             else    count--;
             if(count == 0)
             {
                 RightIntval = i + 1;
                 break;
             }
         }
         vector<int> lpr(preorder.begin() + 1, preorder.begin() + RightIntval + 1);
         vector<int> lpo(postorder.begin(), postorder.begin() + RightIntval);
         root->left = constructFromPrePost(lpr, lpo);
         vector<int> rpr(preorder.begin() + RightIntval + 1, preorder.end());
         vector<int> rpo(postorder.begin() + RightIntval, postorder.begin() + postorder.size() - 1);
         root->right = constructFromPrePost(rpr, rpo);
         return root;
     }
 };*/
class Solution {
public:
    TreeNode* dfs(int PreStart, int PreEnd, int PosStart, int PosEnd)
    {
        if (PreStart >= PreEnd || PosStart >= PosEnd)  return nullptr;
        TreeNode* root = new TreeNode(preorder[PreStart]);
        int count = 0, RightIntval = 0;
        map<int, int> m;
        for (int i = 0; i < PosEnd - PosStart - 1; i++)
        {
            m[preorder[PreStart + i + 1]] += 1;
            if (m[preorder[PreStart + i + 1]])  count++;
            else    count--;
            m[postorder[PosStart + i]] -= 1;
            if (m[postorder[PosStart + i]]) count++;
            else    count--;
            if (count == 0)
            {
                RightIntval = i + 1;
                break;
            }
        }
        root->left = dfs(PreStart + 1, PreStart + RightIntval + 1, PosStart, PosStart + RightIntval);
        root->right = dfs(PreStart + RightIntval + 1, PreEnd, PosStart + RightIntval, PosEnd - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& _preorder, vector<int>& _postorder) {
        int sz = _preorder.size();
        preorder = _preorder;
        postorder = _postorder;
        return dfs(0, sz, 0, sz);
    }
private:
    vector<int> preorder;
    vector<int> postorder;
};