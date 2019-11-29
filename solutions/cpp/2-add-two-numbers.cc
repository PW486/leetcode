#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *nextResult = new ListNode(0);
    ListNode *headNode = nextResult;
    ListNode *nextl1Node = l1;
    ListNode *nextl2Node = l2;

    for (;;) {
      int sum = nextResult->val;

      if (nextl1Node) {
        sum += nextl1Node->val;
        nextl1Node = nextl1Node->next;
      }

      if (nextl2Node) {
        sum += nextl2Node->val;
        nextl2Node = nextl2Node->next;
      }

      if (sum > 9) {
        nextResult->val = sum % 10;
        nextResult->next = new ListNode(sum / 10);
      } else {
        nextResult->val = sum;
      }

      if (nextl1Node == NULL && nextl2Node == NULL) {
        break;
      }

      if (nextResult->next == NULL) {
        nextResult->next = new ListNode(0);
      }
      nextResult = nextResult->next;
    }

    return headNode;
  }
};

int main() {
  ListNode l1n1(2);
  ListNode l1n2(4);
  ListNode l1n3(3);
  l1n1.next = &l1n2;
  l1n2.next = &l1n3;

  ListNode l2n1(5);
  ListNode l2n2(6);
  ListNode l2n3(4);
  l2n1.next = &l2n2;
  l2n2.next = &l2n3;

  Solution s;
  ListNode *result = s.addTwoNumbers(&l1n1, &l2n1);
  for (; result; result = result->next) {
    cout << result->val << '\n';
  }

  return 0;
}
