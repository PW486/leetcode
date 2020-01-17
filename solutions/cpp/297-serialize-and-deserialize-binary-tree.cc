#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  string serialize(TreeNode *root) {
    if (root == NULL)
      return "[]";
    string str = "[";

    bool nextLevel = true;
    queue<TreeNode *> Q;
    Q.push(root);

    while (nextLevel) {
      queue<TreeNode *> R;
      nextLevel = false;

      while (!Q.empty()) {
        auto front = Q.front();
        if (front == NULL) {
          str += "null,";
        } else {
          str += to_string(front->val) + ',';
          R.push(front->left);
          R.push(front->right);

          if (front->left != NULL || front->right != NULL) {
            nextLevel = true;
          }
        }
        Q.pop();
      }
      Q = R;
    }

    if (str.size() > 5) {
      while (true) {
        string last = str.substr(str.size() - 5, str.size());
        if (last.compare("null,") == 0) {
          str = str.substr(0, str.size() - 5);
        } else {
          break;
        }
      }
    }

    str[str.length() - 1] = ']';
    return str;
  }

  TreeNode *deserialize(string data) {
    if (data.compare("[]") == 0)
      return NULL;
    TreeNode *root;
    string numStr = "";
    bool isLeft = true;

    int i = 1;
    for (; i < data.size(); ++i) {
      if (data[i] == ',' || data[i] == ']') {
        int num = stoi(numStr);
        root = new TreeNode(num);

        numStr = "";
        break;
      } else {
        numStr += data[i];
      }
    }
    i++;

    queue<TreeNode *> Q;
    Q.push(root);

    for (; i < data.size(); ++i) {
      if (data[i] == ',' || data[i] == ']') {
        int num = stoi(numStr);
        auto front = Q.front();

        if (isLeft) {
          front->left = new TreeNode(num);
          Q.push(front->left);
        } else {
          front->right = new TreeNode(num);
          Q.push(front->right);
          Q.pop();
        }

        isLeft = !isLeft;
        numStr = "";
      } else if (data[i] == 'n') {
        if (!isLeft) {
          Q.pop();
        }

        isLeft = !isLeft;
        i += 4;
      } else {
        numStr += data[i];
      }
    }

    return root;
  }
};

void printTree(TreeNode *node) {
  if (node == NULL)
    return;

  printTree(node->left);
  cout << node->val << ' ';
  printTree(node->right);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  string str = Codec().serialize(root);
  cout << str << endl;

  TreeNode *result = Codec().deserialize(str);
  printTree(result);
  return 0;
}
