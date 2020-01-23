#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int res = 0;
    unordered_map<int, int> AB;

    for (int a : A)
      for (int b : B)
        AB[a + b]++;

    for (int c : C)
      for (int d : D)
        res += AB[-c - d];

    return res;
  }
};

int main() {
  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};

  cout << Solution().fourSumCount(A, B, C, D) << endl;
  return 0;
}
