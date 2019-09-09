#include "list/list.h"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

int main() {
    Solution solution;
    int arr1[3] = {1, 2, 4};
    int arr2[3] = {1, 3, 4};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    ListNode* l1 = createLinkedList(arr1, size1);
    ListNode* l2 = createLinkedList(arr2, size2);
    printLinkedList(l1);
    printLinkedList(l2);
    ListNode* res = solution.mergeTwoLists(l1, l2);
    printLinkedList(res);
    destroyLinkedList(res);
    destroyLinkedList(l1);
    destroyLinkedList(l2);
    return 0;
}