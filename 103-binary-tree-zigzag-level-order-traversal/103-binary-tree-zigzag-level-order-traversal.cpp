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
    void reverseArr(vector<int>&ds){
        int start=0;
        int end=ds.size()-1;
        while(end>start){
            swap(ds[start++],ds[end--]);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool turn=false;
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
            
            if(turn == true){
                reverseArr(ds);
                ans.push_back(ds);
                turn=0;
            }
            else{
            ans.push_back(ds);
                turn=1;
            }
            
        }
        return ans;
        
        
    }
};