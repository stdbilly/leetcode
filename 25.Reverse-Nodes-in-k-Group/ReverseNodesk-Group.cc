#include "list/list.h"

//参考:
//https://www.cnblogs.com/lichen782/p/leetcode_Reverse_Nodes_in_kGroup.html

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        
        ListNode dummyHead(0);
        dummyHead.next = head;
        ListNode* pre = &dummyHead;
        int i = 0;
        while (head != nullptr) {
            ++i;
            if (i % k == 0) {
                pre = reverse(pre, head->next);
                head = pre->next;
            } else {
                head = head->next;
            }
        }
        return dummyHead.next;
    }

   private:
    ListNode* reverse(ListNode* pre, ListNode* next) {
        ListNode* last = pre->next;
        ListNode* cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.reverseKGroup(head, 3);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}