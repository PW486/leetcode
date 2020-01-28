#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
  bool isInteger() const;
  int getInteger() const;
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
  vector<int> vec;
  int idx;

  void flatten(vector<NestedInteger> &nestedList) {
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger()) {
        vec.push_back(nestedList[i].getInteger());
      } else {
        vector<NestedInteger> list = nestedList[i].getList();
        flatten(list);
      }
    }
  }

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    flatten(nestedList);
    idx = 0;
  }

  int next() { return vec[idx++]; }

  bool hasNext() { return vec.size() > idx; }
};

int main() { return 0; }
