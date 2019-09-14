#include "list.h"

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            } else {
                cur = cur->next;
            }
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.removeElements(head, 6);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}