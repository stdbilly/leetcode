#include "list/list.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        if(!node->next) {
            delete node;
            node = nullptr;
            return;
        }
        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;
        return;
    }
};

int main(){
   Solution solution;
   vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    solution.deleteNode(head->next->next);
    printLinkedList(head);
    destroyLinkedList(head);
   return 0;
}