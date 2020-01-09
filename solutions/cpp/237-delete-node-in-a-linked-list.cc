#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int main() {
  ListNode *node = new ListNode(4);
  node->next = new ListNode(5);
  node->next->next = new ListNode(1);
  node->next->next->next = new ListNode(9);

  Solution().deleteNode(node->next);
  while (node) {
    cout << node->val << endl;
    node = node->next;
  }
  return 0;
}
