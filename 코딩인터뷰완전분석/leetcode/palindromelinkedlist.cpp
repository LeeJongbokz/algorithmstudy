/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        vector<int> v;
        
        while(head != NULL){
            int num = head->val;
            v.push_back(num);
            head = head->next;
        }
        
        int len = v.size();
        bool result = true;
        
        for(int i=0; i<(len/2); i++){
            if(v[i] == v[len-1-i]){
                continue;
            }else{
                result = false;
                break; 
            }
        }
        
        return result; 
        
    }
};
