// 审清题，确定好方法
// 一开始搞个尾插法，明显不好，要及时纠正
// 查链表最大值，基础实现，不清楚，一开始还搞个双指针，不好
// 要考虑特殊情况，比如链表为空；
#include <iostream>
using namespace std;

// 定义链表节点结构
struct Node {
  int value;                       // 节点值
  Node* next;                      // 指向下一个节点的指针
  Node(int v, Node* n = nullptr);  // 构造函数
};

// 自定义堆栈类
class CustomStack {
 private:
  Node* stackTop;     // 主堆栈的栈顶指针
  Node* maxStackTop;  // 最大值堆栈的栈顶指针

 public:
  // 构造函数
  CustomStack();
  // 析构函数，释放所有节点
  ~CustomStack();
  // 入栈操作
  void push(int x);
  // 出栈操作
  void pop();
  // 获取当前最大值
  int getMax();
};

// Node 构造函数实现
Node::Node(int v, Node* n) : value(v), next(n) {}

// CustomStack 构造函数实现
CustomStack::CustomStack() : stackTop(nullptr), maxStackTop(nullptr) {}

// CustomStack 析构函数实现
CustomStack::~CustomStack() {
  while (stackTop) {
    Node* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
  }
  while (maxStackTop) {
    Node* temp = maxStackTop;
    maxStackTop = maxStackTop->next;
    delete temp;
  }
}

void CustomStack::push(int x) {
  // TODO

  Node* newnode = new Node(x);
  if (!stackTop) {
    // cout << "kaistack" << endl;
    stackTop = newnode;
  } else {
    Node* p1 = stackTop;
    newnode->next = p1;
    stackTop = newnode;
  }

  if (maxStackTop) {
    if (x > maxStackTop->value) {
      maxStackTop->value = x;
    }
  } else {
    maxStackTop = new Node(x);
  }
}

void CustomStack::pop() {
  if (!stackTop) {
    return;
  }
  Node* temp = stackTop;
  stackTop = temp->next;
  if (temp->value == maxStackTop->value) {
    Node* p = stackTop;
    int max = 0;

    while (p) {
      if (p->value > max) {
        max = p->value;
      }
      p = p->next;
    }
    // if (p->value > max) {
    //   max = p->value;
    // }
    maxStackTop->value = max;
  }
  // cout << "delete" << temp->value << endl;
  delete temp;
}

int CustomStack::getMax() {
  if (!stackTop) return 0;
  return maxStackTop->value;
}
/*你的代码会被嵌入在这个位置*/

int main() {
  int N;
  cin >> N;        // 读取操作总数
  CustomStack cs;  // 创建自定义堆栈对象
  for (int i = 0; i < N; ++i) {
    int op;
    cin >> op;  // 读取操作类型
    if (op == 0) {
      int X;
      cin >> X;    // 读取入库题目的难度
      cs.push(X);  // 执行入库操作
    } else if (op == 1) {
      cs.pop();  // 执行出库操作
    } else if (op == 2) {
      cout << cs.getMax() << endl;  // 输出当前题库中最难题目的难度
    }
  }
  return 0;
}