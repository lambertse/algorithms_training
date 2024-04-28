//19. Remove Nth Node From End of List
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* point1 = head;
        ListNode* point2 = head;
        while(n--)
            point2=point2->next;
        ListNode* prePoint1 = nullptr;
        while(point2){
            point2=point2->next;
            prePoint1=point1;
            point1=point1->next;
        }
        if(!prePoint1){
            return head->next;
        }
        prePoint1->next = point1->next;
        return head;
    }
};