#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
#define NIL nullptr

typedef int ElemType;

typedef struct ListNode* Position;  // 指针即结点位置
struct ListNode {
  ElemType data_;  // 存储数据
  Position next_;  // 线性表中下一个元素的位置
};

class LinkedList {
 private:
  Position head_;  // 单链表头指针,指向空头结点
  int length_;     // 表长
 public:
  struct ListException  // 异常处理
  {
    std::string error_;
    ListException(std::string s) : error_(s) {};
  };
  LinkedList();                              // 构造函数，初始化一个空的线性表
  ~LinkedList();                             // 析构函数,释放线性表占用的空间
  bool check_circle();                       // 检查是否成环
  LinkedList(const LinkedList&);             // 拷贝构造函数
  LinkedList& operator=(const LinkedList&);  // 赋值运算符重载
  int Josephus(const int& n, const int& m, const int& k);  // 约瑟夫问题
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    LinkedList list;
    cin >> n >> m >> k;
    int ans = list.Josephus(n, m, k);
    LinkedList list2(list);
    LinkedList list3;
    list3 = list2;
    if (list2.check_circle() && list3.check_circle()) {
      cout << ans << endl;
    } else {
      cout << "检测到你没有使用环形链表，这个题不给分哦" << endl;
    }
  }
}
LinkedList::LinkedList() {
  head_ = new ListNode{0, NIL};  // 头指针指向一个空头结点
  head_->next_ = head_;          // 头结点指向自己，形成环
  length_ = 0;
}
LinkedList::~LinkedList() {
  Position p = head_->next_, temp;
  while (p != head_ && p != NIL) {
    temp = p;
    p = p->next_;
    delete temp;
    --length_;
  }
  delete head_;
  if (length_ != 0) {
    std::cout << "释放空间出错，lenth_ = " << length_ << endl;
  }
}
bool LinkedList::check_circle() {
  if (head_ == NIL || head_->next_ == head_) {
    // 如果链表为空或只有头结点，则是一个有效的循环链表
    return true;
  }

  Position slow = head_->next_;  // 慢指针
  Position fast = head_->next_;  // 快指针

  while (fast != NIL && fast->next_ != NIL) {
    slow = slow->next_;         // 慢指针每次移动一步
    fast = fast->next_->next_;  // 快指针每次移动两步

    // 如果快慢指针相遇，说明链表中有环
    if (slow == fast) {
      return true;
    }
  }
  // 如果快指针到达了末尾，说明没有环
  return false;
}
LinkedList::LinkedList(const LinkedList& llist) {
  // 实现拷贝构造函数
  if (&llist.head_ == NULL) return;
  Position temp, p;
  temp = llist.head_->next_;
  length_ = llist.length_;
  head_ = new ListNode{0, head_};
  //   cout << head_ << ' ' << head_->next_ << endl;
  // 产生空头结点
  p = head_;
  for (int i = 0; i < llist.length_; i++) {
    p->next_ = new ListNode{temp->data_, NULL};
    p = p->next_;
    temp = temp->next_;
  }
  //   环形链表开新结点，下一个指针指向NULL，别图省事指向头节点，那样不成
  p->next_ = head_;
}

LinkedList& LinkedList::operator=(const LinkedList& llist) {
  //   // 实现重载赋值运算符

  if (&llist == this) return *this;
  Position p, temp;
  p = head_->next_;
  while (p != head_) {
    temp = p;
    p = p->next_;
    delete temp;
    cout << head_->next_ << endl;
  }
  length_ = 0;
  head_->next_ = head_;
  length_ = llist.length_;
  if (llist.head_->next_ == llist.head_) {
    return *this;
  }

  temp = llist.head_->next_;
  p = head_;
  while (temp != llist.head_) {
    p->next_ = new ListNode{temp->data_, NULL};
    p = p->next_;
    temp = temp->next_;
  }
  p->next_ = head_;
  return *this;
}
// 删除的时候，至少用三个指针，一个cur，一个pre，一个temp存要删的；
// 一开始用两个，temp删掉了还继续用，不出错就怪了；
// 别图省事简化过程，想清楚，别急；
int LinkedList::Josephus(const int& n, const int& m, const int& k) {
  // 实现约瑟夫问题
  Position p = head_;
  length_ = 0;
  for (int i = 1; i <= n; i++) {
    p->next_ = new ListNode{i, NULL};
    p = p->next_;
    length_++;
  }
  p->next_ = head_;
  p = head_;
  //   cout << "构造完成" << endl;

  Position cur = head_->next_, pre = head_, temp;
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i < m; i++) {
      if (length_ == 1) {
        return head_->next_->data_;
      }
      if (cur->data_ == 0) {
        pre = pre->next_;
        cur = cur->next_;
      }
      pre = cur;
      cur = cur->next_;
    }
    if (cur->data_ == 0) {
      pre = pre->next_;
      cur = cur->next_;
    }
    if (j == k) {
      break;
    }
    temp = pre;
    temp->next_ = cur->next_;
    temp = cur;
    cur = cur->next_;

    // p = head_;
    // for (int i = 0; i <= length_; i++) {
    //   cout << p->data_ << ' ';
    //   p = p->next_;
    // }
    // cout << "delete" << temp->data_ << endl;
    // delete temp;
    // cout << pre->data_ << endl;
    length_--;
  }

  //   cout << cur->data_;
  return cur->data_;
}