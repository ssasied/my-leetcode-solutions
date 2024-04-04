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
/*
    my solution with list 60%:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*ca=headA;
        ListNode*cb=headB;
        int cta=1;
        int ctb=1;
        while(ca->next){
            ca=ca->next;
            cta++;
        }
        while(cb->next){
            cb=cb->next;
            ctb++;
        }
        
        int counter=ctb>cta?ctb-cta:cta-ctb;   
             
        ListNode*higher=ctb>=cta?headB:headA;
        ListNode*smaller=ctb<=cta?headB:headA;        
        if(counter==0){
            higher=headB;
            smaller=headA;
        }
        while(counter){
            counter--;
            higher=higher->next;            
        }
        while(higher!=smaller){
            higher=higher->next;
            smaller=smaller->next;
        }
        return higher;
    }*/
    //smart solution with map (didnt think of that)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_map<ListNode*,int>mpp;
    for (auto p = headA ; p!=NULL ; p = p->next){
        mpp[p]=p->val;
    }
    for (auto p = headB ; p!=NULL ; p = p->next){
        if (mpp.find(p)!=mpp.end()) return p;
    }
    return NULL;
    }
    
};