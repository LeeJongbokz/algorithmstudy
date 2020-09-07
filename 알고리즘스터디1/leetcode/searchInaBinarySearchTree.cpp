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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root != NULL){
            
            
            TreeNode* res = new TreeNode();
            TreeNode* res1 = searchBST(root->left, val);
            
            if(root->val == val){
                return root;
            }
            
            TreeNode* res2 = searchBST(root->right, val);
            
            if(res1 != NULL){
                res = res1;
            }else if(res2 != NULL){
                res = res2;
            }else{
                res = NULL;
            }
            
            return res; 
        }else{
            return NULL;
        }
    }
};
