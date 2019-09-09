#include "list/list.h"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two
        // lists. All of these are initialized with the dummy nodes created.
        ListNode* beforeHead = new ListNode(0);
        ListNode* before = beforeHead;
        ListNode* afterHead = new ListNode(0);
        ListNode* after = afterHead;
        while (head) {
            // If the original list node is lesser than the given x,
            // assign it to the before list.
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        // Last node of "after" list would also be ending node of the reformed
        // list
        after->next = nullptr;
        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before->next = afterHead->next;
        return beforeHead->next;
    }
};

int main() {
    Solution solution;
    int arr[6] = {1, 4, 3, 2, 5, 2};
    int size = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.partition(head, 3);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}