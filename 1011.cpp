#include <cstdlib>
#include <string>
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

LinkedList::LinkedList(const LinkedList& llist) {
  if (llist.head_ == NULL) return;

  Position dummy = llist.head_;
  head_ = new ListNode{dummy->data_};
  Position curr = head_;
  ++length_;
  for (int i = 1; i < llist.length_ + 1; ++i) {
    curr->next_ = new ListNode{dummy->next_->data_};
    curr = curr->next_;
    dummy = dummy->next_;
    ++length_;
  }
  curr->next_ = head_;
  length_ = llist.length_;
  return;
}

LinkedList& LinkedList::operator=(const LinkedList& llist) {
  if (&llist == this) return *this;

  if (this->head_ != NULL) {
    Position curr = head_;
    for (; length_ > 0; --length_) {
      curr = head_->next_;
      delete head_;
      head_ = curr;
    }
    head_ = NULL;
    length_ = 0;
  }

  if (llist.head_ == NULL) return *this;

  Position dummy = llist.head_;
  head_ = new ListNode{dummy->data_};
  Position curr = head_;
  ++length_;
  for (int i = 0; i < llist.length_; ++i) {
    curr->next_ = new ListNode{dummy->next_->data_};
    curr = curr->next_;
    dummy = dummy->next_;
    ++length_;
  }
  curr->next_ = head_;
  length_ = llist.length_;
  return *this;
}

int LinkedList::Josephus(const int& n, const int& m, const int& k) {
  if (this->head_ != NULL) {
    Position curr = head_;
    for (; length_ > 0; --length_) {
      curr = head_->next_;
      delete head_;
      head_ = curr;
    }
    head_ = NULL;
  }

  {
    length_ = 0;
    head_ = new ListNode{1};  // n .geq 1
    Position curr = head_;
    ++length_;
    for (int i = 1; i < n; ++i) {
      curr->next_ = new ListNode{i + 1};
      ++length_;
      curr = curr->next_;
    }
    curr->next_ = head_;
    length_ = n - 1;
  }

  int ans = -1, n_left = n;
  for (int i = 0; i < k - 1; ++i) {
    int r = (m + n_left - 2) % n_left;
    for (int j = 0; j < r; ++j) {
      head_ = head_->next_;
    }  // head_ == to_del_->prev
    Position tmp = head_->next_->next_;
    delete head_->next_;
    head_->next_ = tmp;
    --n_left;
    head_ = head_->next_;
  }
  {
    int r = (m - 1) % n_left;
    for (int j = 0; j < r; ++j) {
      head_ = head_->next_;
    }
    ans = head_->data_;
  }

  length_ = n_left - 1;

  return ans;
}
