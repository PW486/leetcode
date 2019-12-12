#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
  queue<int> Q;

public:
  void push(int x) { Q.push(x); }

  int pop() {
    auto back = Q.back();

    while (true) {
      auto front = Q.front();
      Q.pop();

      if (front == back) {
        break;
      }
      Q.push(front);
    }

    return back;
  }

  int top() { return Q.back(); }

  bool empty() { return Q.empty(); }
};

int main() {
  MyStack *obj = new MyStack();

  obj->push(7);
  obj->push(8);
  obj->push(5);
  cout << obj->empty() << endl;
  cout << obj->top() << endl;
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
