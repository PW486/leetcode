#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
      return head;

    ListNode *next = head->next;
    ListNode *even = head->next;
    ListNode *odd = head->next->next;
    head->next = head->next->next;

    while (true) {
      even->next = odd->next;
      if (even->next == NULL)
        break;
      even = even->next;

      odd->next = even->next;
      if (odd->next == NULL)
        break;
      odd = odd->next;
    }
    odd->next = next;

    return head;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = Solution().oddEvenList(head);
  while (result != NULL) {
    cout << result->val << endl;
    result = result->next;
  }

  return 0;
}
