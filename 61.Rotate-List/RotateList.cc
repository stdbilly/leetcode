#include "list/list.h"

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = getLen(head);
        k = k % len;
        ListNode* last = head;
        for (int i = 0; i < k; ++i) {
            last = last->next;
        }
        ListNode* pre = head;
        while (last->next) {
            pre = pre->next;
            last = last->next;
        }
        last->next = head;
        head = pre->next;
        pre->next = nullptr;
        return head;
    }

   private:
    int getLen(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.rotateRight(head, 3);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}