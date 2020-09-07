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
    
    void recursive(TreeNode* root, vector<int>& v){
        
        if(root == nullptr){
            return; 
        }
        
        recursive(root->left, v);
        v.push_back(root->val);
        recursive(root->right, v);
    }
    
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        vector<int> v;
        
        recursive(root, v);
        
        int sum = 0;
        
        for(int i=0; i<v.size(); i++){
            if(L<=v[i] && v[i]<=R){
                sum += v[i];
            }
        }
        
        return sum;          
    }
};
