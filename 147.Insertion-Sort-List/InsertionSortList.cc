#include "list/list.h"

class Solution {
   public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* pre = dummyHead.next;

        while (pre->next) {
            int val = pre->next->val;
            ListNode* next = pre->next->next;
            ListNode* pi = &dummyHead;
            for (; pi != pre; pi = pi->next) {
                if (pi->next->val > val) {
                    ListNode* pj = pi->next;
                    ListNode* swapNode = pre->next;

                    pi->next = swapNode;
                    swapNode->next = pj;
                    pre->next = next;  // pre就是pj
                    break;
                }
            }

            if (pi == pre) pre = pre->next;
        }
        return dummyHead.next;
    }
};

int main() {
    Solution solution;
    vector<int> arr{-1, 5, 3, 4, 0};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.insertionSortList(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}