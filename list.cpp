#include <iostream>

#define kMaxSize 10000
#define NIL -1

typedef int Position;  // 整型下标，表示元素的位置

/* List类的定义 */
template <typename ElemType>
class List{
	private:
		ElemType *data_;  // 存储数据的数组
		Position last_;  //线性表中最后一个元素在数组中的位置
		Position maxsize_; //线性表最大容纳元素个数

	public:
		struct ListException   //异常处理
		{
		    std::string error_;
		    ListException(std::string s):error_(s){};
        };

        List(unsigned=kMaxSize);       //构造函数，初始化一个空的线性表
        List(const List&);             //拷贝构造函数
        List& operator=(const List&);  //重载赋值运算符=
		~List();                       // 析构函数,释放线性表占用的空间

		Position Search(ElemType x);  // 在线性表中查找元素x，查找成功，返回x的位置，否则返回NIL
		void Insert(Position i,ElemType x);  // 在线性表第i个位置上插入元素x
		void Remove(Position i);  // 从线性表中删除第i个元素
        
        template <typename U>
		friend std::ostream& operator<<(std::ostream&, const List<U>&); //输出一个顺序表

        template <typename U>
        friend std::istream& operator>>(std::istream&, List<U>&);      //输入一个顺序表
};
/* 以上为List类的定义 */

/* 基本操作实现 */
template <typename ElemType>
List<ElemType>::List(unsigned list_size)
{
    data_ = new ElemType[list_size]{0};
    last_ = NIL;
    maxsize_ = list_size;
}

template <typename ElemType>
List<ElemType>::List(const List& li)
{
    data_ = new ElemType[li.maxsize_]{0};
    maxsize_ = li.maxsize_;
    last_ = li.last_;
    for (int i=0; i<=last_ ;i++) {
        data_[i] = li.data_[i];
    }
}

template <typename ElemType>
List<ElemType>& List<ElemType>::operator=(const List& li)
{
    if (this != &li) {
        delete[] data_;
        data_ = new ElemType[li.maxsize_]{0};
        maxsize_ = li.maxsize_;
        last_ = li.last_;
        for (int i=0; i<=last_ ;i++) {
            data_[i] = li.data_[i];
        }
    }
    return *this;
}

template <typename ElemType>
List<ElemType>::~List()
{
    delete[] data_;
    last_ = NIL;
}

template <typename ElemType>
std::ostream& operator<<(std::ostream& os, const List<ElemType>& llist)
{
    for (int i=0; i<=llist.last_ ;i++){
        std::cout << llist.data_[i] << ' ';
    }
    return os;
}

template <typename ElemType>
std::istream& operator>>(std::istream& is, List<ElemType>& llist)
{
// input List: n a1 a2 a3 ...
    int n;
    std::cin >> n;

    if ( n > (llist.maxsize_)) {  // 插入元素个数大于顺序表的最大容量，抛出异常
        throw typename List<ElemType>::ListException("元素个数超过线性表最大容量。\n");
    }

    llist.last_ = n-1;

    for (int i = 0; i < n; i++) {
        std::cin >> llist.data_ [i] ;
	}
	return is;
}

/* 算法2-1： 在顺序表list中查找元素x  List::Search(x) */
template <typename ElemType>
Position List<ElemType>::Search(ElemType x)
{
    Position i = 0;
    //to do
    return i;
}
/* 算法2-1 结束 */

//算法2-1 在顺序表 list 中查找元素 x 的 测试主函数
/*int main()
{
    try
    {
        List<int> mylist;
        int x;
        std::cin >> mylist;
        std::cin >> x;

        std::cout << mylist.Search(x) << std::endl;
    }
    catch(List<int>::ListException e)
    {
        std::cout << e.error_ ;
    }
    return 0;
}
*/

/* 算法2-2：在顺序表list的第i个位置上插入元素x  List::Insert(i,x)*/
template <typename ElemType>
void List<ElemType>::Insert(Position i,ElemType x)
{

    
   //to 
}
/* 算法2-2 结束 */

//算法2-2 在顺序表 list 的第 i 个位置上插入元素 x，测试主函数
/*int main()
{
    List<int> mylist;
    try
    {
        int i,x;
        std::cin >> mylist;
        std::cin >> i >> x;
        mylist.Insert(i,x);
        std::cout << mylist <<std::endl;
    }
    catch(List<int>::ListException e)
    {
        std::cout << e.error_ ;
        std::cout << mylist <<std::endl;
    }
    return 0;
}
*/


/* 算法2-3：从顺序表list中删除第i个元素  List::Remove (i)*/
template <typename ElemType>
void List<ElemType>::Remove(Position i)
{

   //to do 
}
/* 算法2-3 结束 */


//算法2-3 从顺序表 list 中删除第 i 个元素,测试主函数
int main() {
    List<int> mylist;
    try {
        std::cin >> mylist;
        Position k;
        std::cin >> k;
        mylist.Remove(k);
        std::cout << mylist << std::endl;
    }
    catch(List<int>::ListException e) {
        std::cout << e.error_ ;
        std::cout << mylist << std::endl;
    }
    return 0;
}

