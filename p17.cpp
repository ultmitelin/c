#include <assert.h>
// 这个思路，要清晰，搞清迭代器指的是什么，什么时候要更新；
// 最后的判断条件，清晰；
// 已经cout后，就return，后面的不再执行

#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  struct Node {       // Node为链式存储的栈内结点类
    int element_;     // 结点存储的元素
    Node *next_;      // 下一个结点地址（自顶向下）
    Node() = delete;  // 创建结点必须指定元素值和下一个结点地址
    Node(int element, Node *next) : element_(element), next_(next) {}
  };
  static void Solve() {  // 对一个序列进行判断，输出结果
    int n;
    std::cin >> n;
    std::string out_seq;
    std::cin >> out_seq;
    MyStackAndGetAns::GetAns(n, out_seq);
  }

 private:
  class MyStackAndGetAns {  // 栈的实现和答案输出
   public:
    MyStackAndGetAns() {  // 构造函数，重置栈顶和栈内元素个数
      top_ = nullptr;
      size_ = 0;
    }
    virtual ~MyStackAndGetAns() {  // 析构函数，清空栈
      while (top_ != nullptr) {
        Node *next = top_->next_;
        delete top_;
        top_ = next;
        assert(size_ > 0);
        size_--;
      }
      assert(size_ == 0);
    }
    void Push(int element) {
      // TODO
      if (this->Empty()) {
        top_ = new Node(element, NULL);
        size_++;
      } else {
        Node *newnode = new Node(element, top_);
        top_ = newnode;
        size_++;
      }
    }
    int Top() {
      if (!this->Empty()) {
        return top_->element_;
      } else {
        std::cout << "bad op" << std::endl;
      }
    }
    void Pop() {
      if (this->Empty()) {
        return;
      }
      Node *temp = top_;
      top_ = top_->next_;
      delete temp;
      size_--;
    }
    bool Empty() {
      if (size_ == 0) {
        return 1;
      }
      return 0;
    }
    // 这个思路，要清晰，搞清迭代器指的是什么，什么时候要更新；
    // 最后的判断条件，清晰；
    // 已经cout后，就return，后面的不再执行

    static void GetAns(int n, std::string out_seq) {
      MyStackAndGetAns a;
      int p = 0;
      int next = 1;
      while (p < n) {
        // a.Push(p + 1);
        int out = out_seq[p] - '0';
        if (!a.Empty() && a.Top() == out) {
          a.Pop();
        } else {
          while (next <= out) {
            a.Push(next);
            next++;
          }
          if (!a.Empty() && a.Top() == out) {
            a.Pop();
          }
        }
        p++;
      }
      if (a.Empty()) {
        std::cout << "yes" << std::endl;
        return;
      }
      std::cout << "no" << std::endl;
    }
    /* 你的代码将会被嵌入在这个位置 */

   private:
    size_t size_;  // 栈内元素数量
    Node *top_;    // 栈顶指针
  };
};

int main() {
  int k;
  std::cin >> k;
  while (k--) {
    Solution::Solve();
  }
  return 0;
}