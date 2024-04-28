// 160. Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "../component/list_node.h"
#include <iostream>

#define ListNode Node<int>
class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aSize = 0, bSize = 0;
        ListNode* tmpA = headA, *tmpB = headB;
        while(headA){
            headA=headA->next;
            aSize++;
        }
        while(headB){
            headB=headB->next;
            bSize++;
        }
        headA = tmpA;headB = tmpB;
        int idx = aSize - bSize;
        while(idx > 0){
            headA = headA->next;
            idx--;
        }
        while(idx < 0){
            headB = headB->next;
            idx++;
        }
        while(headA && headB){
            if(headA->next == headB->next)
                return headA->next;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};