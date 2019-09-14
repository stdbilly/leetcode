#include "list.h"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* tail = &dummyHead;
        while (tail->next && tail->next->next) {
            ListNode* node1 = tail->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            tail->next = node2;
            tail = node1;
        }
        return dummyHead.next;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5, 6};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.swapPairs(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}