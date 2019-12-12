#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> S1, S2;
  int front;

public:
  void push(int x) {
    if (S1.empty()) {
      front = x;
    }
    S1.push(x);
  }

  int pop() {
    int result;

    if (S2.empty()) {
      while (S1.size() > 1) {
        S2.push(S1.top());
        S1.pop();
      }
      result = S1.top();
      S1.pop();
    } else {
      result = S2.top();
      S2.pop();
    }

    return result;
  }

  int peek() {
    if (!S2.empty()) {
      return S2.top();
    }
    return front;
  }

  bool empty() { return S1.empty() && S2.empty(); }
};

int main() {
  MyQueue *obj = new MyQueue();

  obj->push(7);
  obj->push(8);
  obj->push(5);
  cout << obj->empty() << endl;
  cout << obj->peek() << endl;
  cout << obj->pop() << endl;
  obj->push(4);
  cout << obj->pop() << endl;
  obj->push(3);
  cout << obj->pop() << endl;
  cout << obj->pop() << endl;
  cout << obj->pop() << endl;
  cout << obj->empty() << endl;

  return 0;
}
