#include "list.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val != cur->next->val) {
                pre = cur;
                cur = cur->next;
            } else {
                ListNode* delNode = cur->next;
                cur->next = cur->next->next;
                delete delNode;
                delNode = nullptr;

                pre->next = cur;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 1, 2, 3, 3};
    // vector<int> arr{3, 3, 3};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.deleteDuplicates(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}