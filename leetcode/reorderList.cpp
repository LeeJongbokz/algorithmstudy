#include <vector>

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
    void reorderList(ListNode* head) {
        
        vector<int> v;
        ListNode* order = NULL;
        ListNode* temp = NULL;
        ListNode* reverseOrder = NULL;
        ListNode* prev = NULL;
            
        int len = 0;
        int cnt = 0; 
        
        order = head;
        
        while(head != NULL){
            int num = head-> val;
            v.push_back(num);
            head = head->next; 
            len += 1;
        }
        
        while(!v.empty()){
            int num = v.back();
            temp = new ListNode(num);
            if(reverseOrder == NULL){
                reverseOrder = temp;
            }else{
                prev->next = temp;
            }
            
            prev = temp;
            v.pop_back();
        }
        
        temp = NULL;
        prev = NULL;
        
        while(1){
            
            if(cnt == len){
                break;
            }
            
            if(cnt % 2 == 0){
                int num = order->val;
                temp = new ListNode(num);
                
                if(head == NULL){
                    head = temp;
                }else{
                    prev->next = temp;
                }
                
                prev = temp;
                cnt += 1;
                
                order = order->next;
                
            }else if(cnt % 2 == 1){
                int num = reverseOrder->val;
                temp = new ListNode(num);
                
                prev->next = temp;
                prev = temp;
                cnt += 1;
                
                reverseOrder = reverseOrder->next;
            }
            
        }
        
    }
};
