#include "list/list.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* cur = head;
        while (slow) {
            if (cur->val != slow->val) {
                return false;
            } else {
                slow = slow->next;
                cur = cur->next;
            }
        }
        return true;
    }

   private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = nullptr;
        head->next = nullptr;

        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1,2,2,1};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    cout << solution.isPalindrome(head) << endl;
    destroyLinkedList(head);
    return 0;
}