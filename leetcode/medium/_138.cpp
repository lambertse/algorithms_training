#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

   Node* copyRandomList(Node* head) {
        Node* tmp = new Node(0);
        Node* newHead = tmp;
        Node* oldHead = head;
        std::unordered_map<Node*, int> oldMapp;
        std::vector<Node*> newVecc;
        int idx = 0;
        while(head){
            tmp->next = new Node(head->val);
            oldMapp[head] = idx++;
            newVecc.push_back(tmp->next);
            head = head->next;
            tmp = tmp->next;
        }
        newHead = newHead->next;
        tmp = newHead;
        while(oldHead){
            newHead->random = oldHead->random == nullptr ? nullptr : newVecc[oldMapp[oldHead->random]];
            newHead = newHead->next;
            oldHead=oldHead->next;
        }
        return tmp;
    }
};