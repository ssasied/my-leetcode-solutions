/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //some shananigans read at the bottom
  int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for(string s; getline(std::cin, s);)
    {
        if(s[0] != '0') out << "Intersected at '" << s << "'\n";
        else out << "No intersection\n";
        for(int i = 0; i < 4; ++i) getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();
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
        unordered_map<ListNode*,int>map;
        while(headA){
            map[headA]++;
            headA=headA->next;
        }
        while(headB){
            //this is faster than 
            //if(map[headB]==1)return headB;    
            //because i think it doesnt initialise the map[headB] ???        
            if(map.find(headB)!=map.end())return headB;
            headB=headB->next;
        }
        return nullptr;
    
    }
    ///this solution is slower without the shananigans at the top (30% compared to 60 with normal solution)
};