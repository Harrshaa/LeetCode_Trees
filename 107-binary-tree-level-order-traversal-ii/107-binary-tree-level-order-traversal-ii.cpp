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
    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right); 
        
        if(left==0) return right+1;
        else if(right==0) return left+1;
        else
        return max(left,right)+1;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL) return {};
        
        int level=maxDepth(root);
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans(level);
        int currLevel=level-1;
         
        while(q.size()!=0){                       
            int size=q.size();
            vector<int>ds;
            
            for(int i=0;i<size;i++){
                
                TreeNode* temp=q.front();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                
                ds.push_back(q.front()->val);
                q.pop();
            }
            ans[currLevel]=ds;
            currLevel--;            
        }
        return ans;
    }
};