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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        
        queue<pair<TreeNode*, int>> q;
        
        q.push(make_pair(root, 0));
        int level;
        TreeNode* temp;
        bool f = false;
        
        while(!q.empty()){
            level = q.front().second;
            vector<int> vt;
            
            while(!q.empty() && q.front().second == level){
                temp = q.front().first;
                vt.push_back(temp->val);
                
               
                if(temp->left){
                    q.push(make_pair(temp->left, level+1));
                }
                if(temp->right){
                    q.push(make_pair(temp->right, level+1));
                }
               
                q.pop();
            }
            if(f){
                reverse(vt.begin(), vt.end());
            }
            ans.push_back(vt);
            f = !f;
        }
        
        return ans;
    }
};