//206. Reverse linked list

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

#define RECURSIVELY
class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    #ifdef ITERATIVELY
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        ListNode* tmp;
        while(head){
            tmp = node;
            node = new ListNode(head->val);
            node->next=tmp;
            head = head->next;
        }
        return node;
    }
    #endif

    #ifdef RECURSIVELY
    ListNode* recur(ListNode* head, ListNode* &newHead){
        ListNode* cur = nullptr;
        if(!head)
            return nullptr;
        if(head->next)
            cur = recur(head->next, newHead);
        if(!cur){
            newHead = new ListNode(head->val);
            return newHead;
        }
        cur->next = new ListNode(head->val);
        return cur->next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = nullptr;
        recur(head, ret);
        return ret;
    }
    #endif
};