/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* res = NULL;
        
        while(l1 != NULL || l2!= NULL){
            
            if(l1 != NULL && l2 != NULL){
                
                if(l1->val <= l2->val){
                    temp = new ListNode(l1->val);
                    l1 = l1->next;
                }else{
                    temp = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }else if(l1 != NULL && l2 == NULL){
                temp = new ListNode(l1->val);
                l1 = l1->next;
            }else if(l1 == NULL && l2 != NULL){
                temp = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            if(res == NULL){
                res = temp;
            }else{
                prev->next = temp;
            }
            
            prev = temp;
        }
        
        return res;
        
    }
};
