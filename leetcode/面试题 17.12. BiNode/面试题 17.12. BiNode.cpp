/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*class Solution {
 private:
     TreeNode* prev = nullptr;
     TreeNode* head = nullptr;
 public:
     void dfs(TreeNode* root)
     {
         if(root == nullptr)
             return;
         if(root->left)
         {
             dfs(root->left);
         }
         if(head == nullptr)
             head = root;
         prev->right = root;
         root->left = nullptr;
         prev = root;
         dfs(root->right);
     }

     TreeNode* convertBiNode(TreeNode* root) {
         TreeNode* ret = prev = new TreeNode();
         dfs(root);
         delete ret;
         return head;
     }
 };*/
class Solution {
private:
    TreeNode* prev = nullptr;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        convertBiNode(root->right);
        root->right = prev;
        prev = root;
        convertBiNode(root->left);
        root->left = nullptr;
        return prev;
    }
};