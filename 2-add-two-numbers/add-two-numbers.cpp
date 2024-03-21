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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1head=l1;
        bool carry=false;
        while(l2!=nullptr){
            if(carry){
               l1->val+=1;
               carry=false;
            }
            l1->val+=l2->val;           
            if(l1->val>9){
                 l1->val%=10;
                carry=true;
            }
            if(l1->next==nullptr){
                if(l2->next!=nullptr||carry){
                    l1->next=new ListNode(carry);
                    
                    carry=false;
                }
            }
            l1=l1->next;                  
            l2=l2->next;           
        }
        if(l1!=nullptr){
        while(l1->next!=nullptr){
            if(carry){
            l1->val+=1;
            carry=false;}
            if(l1->val>9){
                l1->val=l1->val%10;
                carry=true;
            }
            l1=l1->next;
        }
        if(l1->next==nullptr){
            if(carry){
                l1->val+=1;
                if(l1->val>9){
                l1->val%=10;

                l1->next=new ListNode(carry);}
            }
        }}

        return l1head;
    }
};