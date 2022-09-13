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
int levels(TreeNode* root){
        if(!root) return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void helper(TreeNode* root, vector<vector<int>>&ans, int len, int depth){
        if(!root) return;
        ans[len-depth-1].push_back(root->val);
        if(root->left)helper(root->left, ans, len, depth+1);
        if(root->right)helper(root->right, ans, len , depth+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        int len=levels(root);
        vector<vector<int>>ans(len);
        helper(root,ans, len, 0);
        return ans;
    }
};