#include <bits/stdc++.h>
using namespace std;

class BiNODE {
 public:
  char data;       // 结点值，字符类型，可以按字典序比较大小
  BiNODE* lchild;  // 左子节点
  BiNODE* rchild;  // 右子节点

  BiNODE(char d = '\0');  // 构造函数
  ~BiNODE();              // 析构函数
};

BiNODE::BiNODE(char d) : data(d), lchild(nullptr), rchild(nullptr) {}

BiNODE::~BiNODE() {
  delete lchild;
  delete rchild;
}

class BinaryTree {
 public:
  BinaryTree(BiNODE* r = nullptr);  // 构造函数
  ~BinaryTree();                    // 析构函数

  BiNODE* BuildTree();                        // 构建二叉树的函数
  void Recursion_Pre_Order(BiNODE* node);     // 递归前序遍历函数
  void NoRecursion_Pre_Order(BiNODE* node);   // 非递归前序遍历函数
  void Recursion_In_Order(BiNODE* node);      // 递归中序遍历函数
  void NoRecursion_In_Order(BiNODE* node);    // 非递归中序遍历函数
  void Recursion_Post_Order(BiNODE* node);    // 递归后序遍历函数
  void NoRecursion_Post_Order(BiNODE* node);  // 非递归后序遍历函数
  void Hierachicalorder(BiNODE* node);        // 层次遍历函数

  int Size_Of_Tree(BiNODE* node);       // 计算二叉树大小的函数
  int Height_Of_Tree(BiNODE* node);     // 计算二叉树高度的函数
  bool Is_Full_Tree(BiNODE* node);      // 判断是否为满二叉树的函数
  bool Is_Complete_Tree(BiNODE* node);  // 判断是否为完全二叉树的函数
  bool Is_Perfect_Tree(BiNODE* node);   // 判断是否为完美二叉树的函数
  BiNODE* GetRoot();                    // 获取根节点的函数
  void SetRoot(BiNODE* node);           // 修改根节点的函数

 private:
  BiNODE* root;                 // 二叉树的根节点
  void freeTree(BiNODE* node);  // 释放二叉树节点的函数
};

BinaryTree::BinaryTree(BiNODE* r) : root(r) {}

BinaryTree::~BinaryTree() { freeTree(root); }

void BinaryTree::freeTree(BiNODE* node) {
  if (node) {
    delete node;
  }
}

BiNODE* BinaryTree::GetRoot() { return root; }

void BinaryTree::SetRoot(BiNODE* node) { root = node; }

int main(void) {
  BinaryTree tree;
  tree.BuildTree();

  tree.Recursion_Pre_Order(tree.GetRoot());
  printf("\n");

  tree.NoRecursion_Pre_Order(tree.GetRoot());
  printf("\n");

  tree.Recursion_In_Order(tree.GetRoot());
  printf("\n");

  tree.NoRecursion_In_Order(tree.GetRoot());
  printf("\n");

  tree.Recursion_Post_Order(tree.GetRoot());
  printf("\n");

  tree.NoRecursion_Post_Order(tree.GetRoot());
  printf("\n");

  tree.Hierachicalorder(tree.GetRoot());
  printf("\n");

  printf("%d\n", tree.Size_Of_Tree(tree.GetRoot()));
  printf("%d\n", tree.Height_Of_Tree(tree.GetRoot()));
  printf("%c\n", tree.Is_Full_Tree(tree.GetRoot()) ? 'T' : 'F');
  printf("%c\n", tree.Is_Complete_Tree(tree.GetRoot()) ? 'T' : 'F');
  printf("%c\n", tree.Is_Perfect_Tree(tree.GetRoot()) ? 'T' : 'F');

  return 0;
}
BiNODE* BinaryTree::BuildTree() {
  int n;
  cin >> n;
  if (n == 0) {
    return NULL;
  }
  vector<char> pre(n);
  vector<char> in(n);
  for (int i = 0; i < n; cin >> pre[i], i++);
  for (int i = 0; i < n; cin >> in[i], i++);
  unordered_map<char, int> inord;
  for (int i = 0; i < n; i++) {
    inord[in[i]] = i;
  }
  int index = 0;
  function<BiNODE*(int, int)> buildchild = [&](int inst, int inend) -> BiNODE* {
    if (inst > inend) return NULL;
    char rootval = pre[index++];
    BiNODE* root = new BiNODE(rootval);
    if (inst == inend) {
      return root;
    }
    int rootp = inord[rootval];
    root->lchild = buildchild(inst, rootp - 1);
    root->rchild = buildchild(rootp + 1, inend);
    return root;
  };
  root = buildchild(0, n - 1);
  return root;

};  // 前序+中序建树，在函数中处理输入

void BinaryTree::Recursion_Pre_Order(BiNODE* root) {
  if (!root) {
    return;
  }
  cout << root->data << ' ';
  Recursion_Pre_Order(root->lchild);
  Recursion_Pre_Order(root->rchild);

};  // 递归前序遍历（*）
void BinaryTree::NoRecursion_Pre_Order(BiNODE* root) {
  if (root == nullptr) return;  // 添加空树检查
  stack<BiNODE*> st;
  st.push(root);
  while (!st.empty()) {
    BiNODE* cur = st.top();
    st.pop();
    cout << cur->data << ' ';
    if (cur->rchild) {
      st.push(cur->rchild);
    }
    if (cur->lchild) {
      st.push(cur->lchild);
    }
  }
};  // 非递归前序遍历（*）
void BinaryTree::Recursion_In_Order(BiNODE* root) {
  if (!root) {
    return;
  }
  Recursion_In_Order(root->lchild);
  cout << root->data << ' ';
  Recursion_In_Order(root->rchild);
};  // 递归中序遍历（*）
void BinaryTree::NoRecursion_In_Order(BiNODE* root) {
  if (root == nullptr) return;  // 添加空树检查
  stack<BiNODE*> st;
  // st.push(root);
  // BiNODE*cur=st.pop;
  BiNODE* cur = root;
  while (cur || !st.empty()) {
    while (cur) {
      st.push(cur);
      cur = cur->lchild;
      /* code */
    }
    cur = st.top();
    cout << cur->data << ' ';
    st.pop();
    cur = cur->rchild;
  }

};  // 非递归中序遍历
void BinaryTree::Recursion_Post_Order(BiNODE* root) {
  if (!root) {
    return;
  }
  Recursion_Post_Order(root->lchild);
  Recursion_Post_Order(root->rchild);
  cout << root->data << ' ';
};  // 递归后序遍历（*）
void BinaryTree::NoRecursion_Post_Order(BiNODE* root) {
  if (!root) {
    return;
  }
  stack<BiNODE*> st;
  BiNODE* cur = root;
  BiNODE* lastv = NULL;
  while (cur || !st.empty()) {
    while (cur) {
      st.push(cur);
      cur = cur->lchild;
    }
    cur = st.top();
    if (!cur->rchild || cur->rchild == lastv) {
      cout << cur->data << ' ';
      lastv = cur;
      st.pop();
      cur = nullptr;
    } else {
      cur = cur->rchild;
    }
  }

};  // 非递归后序遍历
void BinaryTree::Hierachicalorder(BiNODE* root) {
  if (root == nullptr) return;  // 添加空树检查
  queue<BiNODE*> q;
  BiNODE* cur = root;
  q.push(cur);
  while (!q.empty()) {
    cur = q.front();
    cout << cur->data << ' ';
    q.pop();
    if (cur->lchild) {
      q.push(cur->lchild);
    }
    if (cur->rchild) {
      q.push(cur->rchild);
    }
  }

};  // 层次遍历（*）

int BinaryTree::Size_Of_Tree(BiNODE* root) {
  if (!root) {
    return 0;
  }
  return Size_Of_Tree(root->lchild) + Size_Of_Tree(root->rchild) + 1;
};  // 求结点个数
int BinaryTree::Height_Of_Tree(BiNODE* root) {
  if (!root) {
    return 0;
  }
  return max(Height_Of_Tree(root->lchild), Height_Of_Tree(root->rchild)) + 1;
};  // 返回二叉树的高度，这里定义空树高度为0.无需输出，返回即可
bool BinaryTree::Is_Full_Tree(BiNODE* root) {
  if (!root) return true;  // 空树视为满二叉树

  // 如果当前节点是叶子节点
  if (!root->lchild && !root->rchild) return true;

  // 如果当前节点有两个子节点，则递归检查左右子树
  if (root->lchild && root->rchild)
    return Is_Full_Tree(root->lchild) && Is_Full_Tree(root->rchild);

  // 如果只有一个子节点，则不是满二叉树
  return false;
};  // 判断是否是满二叉树
bool BinaryTree::Is_Complete_Tree(BiNODE* root) {
  if (!root) {
    return true;
  }
  queue<BiNODE*> q;
  q.push(root);
  bool flag = false;
  while (!q.empty()) {
    BiNODE* cur = q.front();
    q.pop();
    if (cur->lchild) {
      if (flag) return false;
      q.push(cur->lchild);
    } else {
      flag = true;
    }
    if (cur->rchild) {
      if (flag) return false;
      q.push(cur->rchild);
    } else {
      flag = true;
    }
  }
  return true;

};  // 判断是否是完全二叉树
bool BinaryTree::Is_Perfect_Tree(BiNODE* root) {
  if (!root) return true;
  int h = Height_Of_Tree(root);
  int num = Size_Of_Tree(root);
  if (num == pow(2, h) - 1) {
    return true;
  }
  return false;
};  // 判断是否是完美二叉树