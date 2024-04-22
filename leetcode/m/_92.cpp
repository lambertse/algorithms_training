// 92. Reverse Linked List II
#include "../component/list_node.h"
#include <iostream>
using namespace std;
#define ListNode Node<int>
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
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    ListNode* recur(ListNode* head, int cur, int right, ListNode* &post, ListNode* &nextPost){
        if(cur == right){
            post=head;
            nextPost = head->next;
            return head;
        }
        ListNode* tail = recur(head->next, cur+1, right, post, nextPost);
        tail->next = head;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        --left;--right;
        if(left == right) return head;
        int curIdx = 0;
        ListNode* ret = head;
        while (curIdx < left-1) {head=head->next; curIdx+=1;};
        ListNode* preHead = nullptr;
        if(left == 0){
            preHead = nullptr;
        }else{
            curIdx++;
            preHead = head;
            head = head->next;
        }
        ListNode* nextPost = nullptr;
        ListNode* post = nullptr;
        ListNode* tmp = recur(head, curIdx, right, post, nextPost);
        if(preHead) {
            preHead->next = post;
            tmp->next = nextPost;
            return ret;    
        }
        tmp->next = nextPost;
        return post;
        
    }   
};

int main(){
    Solution s;
    ListNode* head = generateListNode<int>({1,2,3,4,5});
    ListNode* tmp = s.reverseBetween(head, 0,3);
    printNodes(tmp);
}