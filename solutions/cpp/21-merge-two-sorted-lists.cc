#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL && l2 == NULL)
      return NULL;
    if (l1 == NULL)
      return l2;
    if (l2 == NULL)
      return l1;

    ListNode *root;
    if (l1->val < l2->val) {
      root = new ListNode(l1->val);
      l1 = l1->next;
    } else {
      root = new ListNode(l2->val);
      l2 = l2->next;
    }

    ListNode *node = root;

    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        node->next = new ListNode(l1->val);
        node = node->next;
        l1 = l1->next;
      } else {
        node->next = new ListNode(l2->val);
        node = node->next;
        l2 = l2->next;
      }
    }

    while (l1 != NULL) {
      node->next = new ListNode(l1->val);
      node = node->next;
      l1 = l1->next;
    }

    while (l2 != NULL) {
      node->next = new ListNode(l2->val);
      node = node->next;
      l2 = l2->next;
    }

    return root;
  }
};

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *result = Solution().mergeTwoLists(l1, l2);
  while (result != NULL) {
    cout << result->val << ' ';
    result = result->next;
  }

  return 0;
}
