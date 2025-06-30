#define MAX_SIZE 100000
#define NIL -1
#include <iostream>
using namespace std;
typedef int ElemType;  // 元素类型，本题中定义元素类型为整型
typedef int
    Position;  // 元素位置，这里我们用元素在线性表存储数据的数组中的下标表示元素位置

class List {
 private:
  ElemType *_data;  // 存储数据的数组，数据从下标为 0 的位置开始存储
  Position
      _last;      // 线性表中最后一个元素在数组中的下标，注意数组的下标从 0 开始
  int _max_size;  // 线性表最大能容纳的元素个数
 public:
  struct ListException  // 异常处理
  {
    std::string error;
    ListException(std::string s) : error(s) {};
  };
  List(
      unsigned =
          MAX_SIZE);  // 构造函数，初始化一个空的线性表，根据指定的最大长度分配连续的内存空间
  List(const List &);
  List &operator=(const List &);
  ~List();  // 析构函数，释放线性表占用的空间

  Position search(ElemType x);            // 在线性表中查找元素 x
  bool insert(Position idx, ElemType x);  // 在线性表下标为 idx 的位置插入元素 x
  ElemType remove(Position idx);          // 删除线性表中下标为 idx 的元素

  friend std::istream &operator>>(std::istream &, List &);  // 读入一个线性表
};
// 你需要完成下列函数的函数体：

/**
 * 【线性表查找操作】
//  * @param  x   [目标元素的值 x]
//  * @return     [存在值为 x 的元素则返回其第一次出现的下标，否则返回 NIL]
 */
Position List::search(ElemType x) {
  // TODO
}

/**
 * 【线性表插入操作】
 * @param  idx [插入元素的位置（以下标表示） idx]
 * @param  x   [被插入的元素值 x]
 * @return     [返回是否成功执行插入操作]
 */
bool List::insert(Position idx, ElemType x) {
  // TODO
}

/**
 * 【线性表删除操作】
 * @param  idx [被删除的元素下标 idx]
 * @return     [成功执行则返回被删除的元素的值，否则返回 NIL]
 */
ElemType List::remove(Position idx) {
  // TODO
}