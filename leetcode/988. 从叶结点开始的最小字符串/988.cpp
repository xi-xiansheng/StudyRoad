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
class Solution {
public:
    bool cmp(const string& s1, const string& s2)
    {
        int i = 0, sz1 = s1.size();
        int j = 0, sz2 = s2.size();
        while (i < sz1 && j < sz2)
        {
            if (s1[i] != s2[j])  break;
            i++;
            j++;
        }
        if (i == sz1)    return true;
        if (j == sz2)    return false;
        return s1[i] < s2[j];
    }
    void dfs(TreeNode* root, string s)
    {
        if (!root)
        {
            std::reverse(s.begin(), s.end());
            if (ans == "")   ans = s;
            if (cmp(s, ans)) ans = s;
            return;
        }
        string s1 = "a";
        s1[0] += root->val;
        s += s1;
        if (root->left && root->right)
        {
            dfs(root->left, s);
            dfs(root->right, s);
        }
        else if (root->left)
        {
            dfs(root->left, s);
        }
        else
        {
            dfs(root->right, s);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        dfs(root, string(""));
        return ans;
    }
private:
    string ans;
};