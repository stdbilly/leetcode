#include "list/list.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = pre->next;
        while (cur) {
            int count = 0;
            ListNode* p = cur;
            while (p && p->val == cur->val) {
                ++count;
                p = p->next;
            }
            if (count > 1) {
                pre->next = p;
            } else {
                pre = cur;
            }

            cur = p;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
    Solution solution;
    int arr[7] = {1, 2, 3, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.deleteDuplicates(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}