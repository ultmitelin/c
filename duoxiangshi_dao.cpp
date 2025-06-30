// while循环，不管什么情况，最后一定记着更新判断条件，使循环向结束的方向进行
// 看题，清晰理解题意；清晰底层逻辑；别急
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

struct node {
  int c;
  int e;
  node* next;
  node() {}
  node(int c, int e) : c(c), e(e), next(NULL) {}
};
class Polynomial {
 private:
  node* head;

 public:
  Polynomial();                                    // 默认构造函数
  Polynomial(const Polynomial& other);             // 拷贝构造函数
  Polynomial& operator=(const Polynomial& other);  // 赋值运算符重载
  ~Polynomial();                                   // 析构函数
  void insert(int c, int e);  // 参数 c 表示系数，e 表示指数。
  Polynomial
  derivative();  // 根据每项的指数进行求导，新的系数是原系数乘以指数，指数减 1
  void print();  // 打印函数：按顺序打印多项式的每一项
  void clear();  // 清除函数：释放链表中所有节点的内存并将头指针置为 NULL
};
Polynomial::Polynomial() : head(NULL) {}
Polynomial::Polynomial(const Polynomial& other) : head(NULL) {
  if (other.head == NULL) return;

  head = new node(other.head->c, other.head->e);
  node* current = head;
  node* other_current = other.head->next;

  while (other_current != NULL) {
    current->next = new node(other_current->c, other_current->e);
    current = current->next;
    other_current = other_current->next;
  }
}
Polynomial& Polynomial::operator=(const Polynomial& other) {  // 赋值运算符重载
  if (this == &other) {
    return *this;
  }

  clear();

  if (other.head != NULL) {
    head = new node(other.head->c, other.head->e);
    node* current = head;
    node* other_current = other.head->next;

    while (other_current != NULL) {
      current->next = new node(other_current->c, other_current->e);
      current = current->next;
      other_current = other_current->next;
    }
  }

  return *this;
}
void Polynomial::clear() {
  node* now = head;
  while (now != NULL) {
    node* tmp = now;
    now = now->next;
    delete tmp;
  }
  head = NULL;
}
Polynomial::~Polynomial() { clear(); }
void Polynomial::print() {
  node* now = head;
  if (now == NULL) {
    cout << "0" << endl;
    return;
  }
  while (now != NULL) {
    cout << now->c << "x^" << now->e << " ";
    now = now->next;
  }
  cout << endl;
}
void Polynomial::insert(int c, int e) {
  // TODO
  node* now = head;
  node* pre = head;
  // 双指针一起，不用再遍历一次，提高效率，找到的curr是第一个小于目标次数的，要加在它前面，又因为是单链表，所以只能双指针
  node* temp = new node(c, e);
  if (!head || e > head->e) {
    // *temp= a(c,e);
    temp->next = head;
    head = temp;
    // cout << "插入" << c << ' ' << e << endl;
    return;
  } else {
    // now = now->next;
    while (now && now->e >= e) {
      if (now->e == e) {
        now->c += c;
        delete temp;
        return;
      }
      pre = now;
      now = now->next;
    }
    // 前一个判定条件确保在有效范围内，若要补到最后一个上，也这么搞；所以次数相等要在里面解决；
    // 要新开空间，否则定义的无效，函数完成就没了
    pre->next = temp;
    temp->next = now;
    // cout << "插入" << c << ' ' << e << endl;
    return;
  }

  /*  node* newNode = new node(c, e);

      // 如果是第一个元素 或者
  新加入的项幂次大于现有最高幂次，则将此节点设为首元 if (!head || e > head->e){
          newNode -> next = head;
          head = newNode;
          return ;
      }

      // 查找正确的位置来进行插入
      node* prev = nullptr;
      node* curr = head;

      while(curr && e <= curr->e){
          if(e == curr->e){   // 相同次数则合并同类项
              curr->c += c;
              delete newNode; // 删除多余的新建节点
              return ;
          }
          prev = curr;
          curr = curr->next;
      }

      // 插入新的结点到适当位置
      prev->next = newNode;
      newNode->next = curr;
    */
}
Polynomial Polynomial::derivative() {
  // Polynomial a1;
  // node* curr = head;
  // while (curr) {
  //   if (curr->e > 0) {
  //     a1.insert((curr->c) * (curr->e), curr->e - 1);
  //     // cout << "插入" << (curr->c) * (curr->e) << ' ' << curr->e - 1
  //     <<endl; curr = curr->next;
  //   } else if (curr->e == 0) {
  //     curr = curr->next;
  //   }
  //   // curr->e == 0也要给处理方式，否则curr不等于NUL会陷入死循环出不来；
  // }
  // return a1;

  node* curr = head;
  node* pre = head;
  while (curr) {
    if (curr->e > 0) {
      curr->c = (curr->c) * (curr->e);
      curr->e--;
      pre = curr;
      curr = curr->next;
    } else if (curr->e == 0) {
      if (curr == head) {
        head = NULL;
      }
      node* temp = curr;
      pre->next = curr->next;

      curr = curr->next;
      delete temp;
    }
  }
  return *this;
}
signed main() {
  Polynomial p;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c, e;
    cin >> c >> e;
    p.insert(c, e);
  }
  p.print();
  Polynomial p2 = p.derivative();

  // Polynomial p2 = p;

  cout << endl;
  p2.print();
  cout << "xxx";
}