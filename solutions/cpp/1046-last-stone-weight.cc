#include <iostream>
#include <set>
#include <vector>

using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
};

class MaxHeap {
  int *harr;
  int capacity;
  int heap_size;

public:
  MaxHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
  }

  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return (2 * i + 1); }
  int right(int i) { return (2 * i + 2); }

  void insert(int k) {
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] < harr[i]) {
      swap(&harr[i], &harr[parent(i)]);
      i = parent(i);
    }
  }

  int extractMax() {
    if (heap_size <= 0) {
      return 0;
    }
    if (heap_size == 1) {
      heap_size--;
      return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);

    return root;
  }

  void MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int biggest = i;
    if (l < heap_size && harr[l] > harr[i])
      biggest = l;
    if (r < heap_size && harr[r] > harr[biggest])
      biggest = r;
    if (biggest != i) {
      swap(&harr[i], &harr[biggest]);
      MaxHeapify(biggest);
    }
  }
};

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    multiset<int> s(begin(stones), end(stones));
    while (s.size() > 1) {
      auto w1 = *prev(s.end());
      s.erase(prev(s.end()));
      auto w2 = *prev(s.end());
      s.erase(prev(s.end()));
      if (w1 - w2 > 0)
        s.insert(w1 - w2);
    }
    return s.empty() ? 0 : *s.begin();
  }

  int lastStoneWeightMaxHeap(vector<int> &stones) {
    MaxHeap *heap = new MaxHeap(30);
    for (int stone : stones) {
      heap->insert(stone);
    }

    while (true) {
      int yRock = heap->extractMax();
      if (yRock == 0)
        break;
      int xRock = heap->extractMax();
      if (xRock == 0)
        return yRock;

      int result = yRock - xRock;
      if (result != 0) {
        heap->insert(result);
      }
    }

    return 0;
  }
};

int main() {
  vector<int> stones = {2, 7, 4, 1, 8, 1};
  cout << Solution().lastStoneWeight(stones) << endl;

  return 0;
}
