#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == NULL)
      return NULL;

    ListNode *reverse = new ListNode(head->val);
    ListNode *previous = reverse;

    for (ListNode *node = head->next; node != NULL; node = node->next) {
      reverse = new ListNode(node->val);
      reverse->next = previous;
      previous = reverse;
    }

    return reverse;
  }
};

int main() {
  ListNode *node = new ListNode(1);
  node->next = new ListNode(2);
  node->next->next = new ListNode(3);
  node->next->next->next = new ListNode(4);
  node->next->next->next->next = new ListNode(5);

  ListNode *result = Solution().reverseList(node);
  for (ListNode *temp = result; temp != NULL; temp = temp->next) {
    cout << temp->val << endl;
  }

  return 0;
}
