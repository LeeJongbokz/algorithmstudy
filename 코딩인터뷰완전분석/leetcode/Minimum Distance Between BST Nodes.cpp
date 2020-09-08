// 20분

#include <cmath>
#include <algorithm> 

const int INF = 99999999;
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
    
    int minDiff = INF;
    
    void recursive(TreeNode* root, vector<int>&v){
        
        if(root == nullptr){
            return;
        }
        
        int data = root->val;
        v.push_back(data);
        
        recursive(root->left, v);
        recursive(root->right, v);
        
    }
    
    
    int minDiffInBST(TreeNode* root) {
        
        vector<int>v;
        
        recursive(root, v);
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<v.size()-1; i++){
            minDiff = min(minDiff, abs(v[i]-v[i+1]));
        }
        
        return minDiff; 
        
    }
};
