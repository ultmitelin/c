// 进位jin的使用，很好，一开始的想法（做个标记，判断标记，进位入栈，不好）
// 回来的路上想了想，明显重新定义进位，每次更新，没有的时候jin=0；明显好很多；
// 一种实现特别复杂，写起来麻烦的时候，别急，再想想有没有别的路；别硬着头皮和烂路死磕；

#include <iostream>
using namespace std;

#define MAX_SIZE 100010

struct node  // 表示单链表的一个节点
{
  int val;     // 表示当前节点的值
  node *next;  // 表示指向下一节点的指针
  node() {}
  node(int v) : val(v), next(NULL) {}  // 构造一个值为 v 的节点的构造函数
};

class Stack  // 表示一个栈
{
 private:
  int capacity;  // 表示栈最多能存储的元素个数
  int size;      // 表示当前栈中存储的元素个数
  int *data;     // 存储栈中元素的数组，默认元素类型为整型
 public:
  Stack(unsigned = MAX_SIZE);  // 构造函数，初始化一个空栈
  ~Stack();                    // 析构函数
  friend std::istream &operator>>(std::istream &,
                                  Stack &);  // 读入一个大整数，存储在栈中
  bool empty();                              // 返回栈是否为空

  void push(int x);  // 向栈顶压入一个元素
  int top();         // 返回栈顶元素
  void pop();        // 弹出栈顶的元素，注意这个函数没有返回值
};

node *add(
    Stack &s1,
    Stack &
        s2);  // 将两个以栈的形式表示的非负大整数相加，得到的结果存入链表后返回（需要完成）

int main() {
  Stack s1, s2;
  cin >> s1 >> s2;
  node *res = add(s1, s2);
  while (res != NULL) {
    cout << res->val;
    res = res->next;
  }
  return 0;
}

Stack::Stack(unsigned sz) {
  data = new int[sz]{0};
  capacity = sz;
  size = 0;
}

Stack::~Stack() {
  delete[] data;
  capacity = 0;
  size = 0;
}

std::istream &operator>>(std::istream &is, Stack &st) {
  string s;
  std::cin >> s;
  int sz = s.size();

  for (int i = 0; i < sz; i++) {
    st.push(s[i] - '0');
  }
  return is;
}

bool Stack::empty() { return !size; }

/**
 * 【元素入栈操作】
 * @param  x   [压入栈中的元素的值]
 * @return     []
 */
void Stack::push(int x) {
  data[size] = x;
  size++;
  return;
}

/**
 * 【查询栈顶元素操作】
 * @param      []
 * @return     [栈顶元素的值]
 */
int Stack::top() {
  return data[size - 1];
  // TODO
}

/**
 * 【弹出栈顶元素操作】
 * @param      []
 * @return     []
 */
void Stack::pop() {
  // TODO
  size--;
  return;
}

/**
 * 【大整数相加操作】
 * @param  s1,s2 [以栈的形式表示的非负大整数]
 * @return       [两个大整数的和的链表表头指针]
 */
node *add(Stack &s1, Stack &s2) {
  // TODO
  Stack result;
  int jin = 0;

  while ((!s1.empty()) && (!s2.empty())) {
    int x = 0;
    x = jin + s1.top() + s2.top();
    if (x >= 10) {
      result.push(x % 10);
      jin = x / 10;
    } else {
      result.push(x);
      jin = 0;
    }
    s1.pop();
    s2.pop();
  }
  while (!s1.empty()) {
    int x = 0;
    x = jin + s1.top();
    if (x >= 10) {
      result.push(x % 10);
      jin = x / 10;
    } else {
      result.push(x);
      jin = 0;
    }
    s1.pop();
  }
  while (!s2.empty()) {
    int x = 0;
    x = jin + s2.top();
    if (x >= 10) {
      result.push(x % 10);
      jin = x / 10;
    } else {
      result.push(x);
      jin = 0;
    }
    s2.pop();
  }
  if (jin) {
    result.push(jin);
  }
  node *head = new node(result.top());
  result.pop();
  node *p = head;
  while (!result.empty()) {
    p->next = new node(result.top());
    p = p->next;
    result.pop();
  }
  return head;
}
