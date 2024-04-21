//143. Reordered list
#include <iostream>
#include "../component/list_node.cpp"
using namespace std;

#define ListNode Node<int>

class Solution {
public:

    Solution(){
      std::ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);  
    }
    inline int getSize(ListNode* head){
        int size = 0;
        while(head && ++size) head=head->next;
        return size;    
    }
    void recur(ListNode* &preMid, ListNode* &postMid, ListNode* midNode){
        if(preMid->next != midNode)
            recur(preMid->next, postMid, midNode);
        ListNode* nextPostMid =  postMid->next;
        ListNode* tmp = preMid->next;
        preMid->next = postMid;
        postMid->next = tmp;
        postMid = nextPostMid;
    }
    void reorderList(ListNode* head) {
        int size = getSize(head);
        if(size <= 2) return;
        ListNode* preMid = head;
        ListNode* postMid = head;
        int mid = (size%2!=0)?size/2: size/2-1;
        while(mid>=0) 
        {
            preMid = postMid;
            postMid=postMid->next;
            mid--;
        }
        preMid->next = nullptr;
        ListNode* midNode = size%2!=0? preMid : nullptr;
        preMid = head;
        recur(preMid, postMid, midNode);
        head = preMid;
    }
};

int main(){
    ListNode* nodes = generateListNode<int>({1,2,3,4,5});
    Solution s;
    s.reorderList(nodes);
    printNodes(nodes);
}