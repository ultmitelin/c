#include <iostream>

class Queue {
 private:
  struct Node {
    int citizen;
    Node *next;
    Node(int c) : citizen(c), next(nullptr) {}
  };

  Node *front;  // 队列的头指针
  Node *rear;   // 队列的尾指针

 public:
  Queue();                           // 无参构造函数
  Queue(const Queue &q);             // 拷贝构造函数
  Queue &operator=(const Queue &q);  // 赋值运算符重载
  ~Queue();                          // 析构函数

  bool isEmpty() const;
  void enqueueFront(int citizen);
  void enqueueRear(int citizen);
  int dequeue();
  void remove(int citizen);
};

// 无参构造函数
Queue::Queue() : front(nullptr), rear(nullptr) {}

// 拷贝构造函数
Queue::Queue(const Queue &q) {
  front = rear = nullptr;  // 初始化为空队列
  Node *temp = q.front;    // 从源队列的头开始遍历
  while (temp != nullptr) {
    enqueueRear(temp->citizen);  // 逐个复制节点
    temp = temp->next;
  }
}

// 赋值运算符重载
Queue &Queue::operator=(const Queue &q) {
  if (this != &q) {
    // 清空当前队列
    while (!isEmpty()) {
      dequeue();
    }

    // 复制源队列
    Node *temp = q.front;
    while (temp != nullptr) {
      enqueueRear(temp->citizen);
      temp = temp->next;
    }
  }
  return *this;
}

// 析构函数
Queue::~Queue() {
  while (front != nullptr) {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
}
bool Queue::isEmpty() const {
  return front == nullptr;

  // TODO
}
// 说明：检查队列是否为空，若为空，则返回 true，否则返回 false。

void Queue::enqueueFront(int citizen) {
  // TODO
  Node *newnode = new Node(citizen);
  if (isEmpty()) {
    front = rear = newnode;
  } else {
    newnode->next = front;
    front = newnode;
  }
}
// 说明：从队列前端插入元素 citizen。

void Queue::enqueueRear(int citizen) {
  // TODO
  if (isEmpty()) {
    front = new Node(citizen);
    rear = front;
    // std::cout << "fff+" << citizen << std::endl;

    return;
  }
  rear->next = new Node(citizen);
  rear = rear->next;
  // std::cout << "rrr+" << citizen << std::endl;

  // Node *t1 = front, *t2 = front;
  // t1 = t1->next;
  // while (t1) {
  //   t1 = t1->next;
  //   t2 = t2->next;
  //   /* code */
  // }
  // t2->next = new Node(citizen);
  // t2 = t2->next;
  // t2->next = rear;
  return;
}
// 说明：从队列后端插入元素 citizen。

int Queue::dequeue() {
  // TODO
  if (isEmpty()) {
    return -1;
  }
  int x = front->citizen;
  Node *temp = front;
  front = front->next;
  if (front == NULL) {
    rear = NULL;
  }
  delete temp;
  return x;
}
// 说明：从队列前端移除并返回元素。如果队列为空，返回 -1 表示错误。

void Queue::remove(int citizen) {
  // TODO
  if (isEmpty()) return;
  Node *temp = front;
  if (front->citizen == citizen) {
    front = front->next;
    if (rear == temp) rear = nullptr;
    delete temp;
    return;
  }
  temp = temp->next;
  Node *sec = front;

  while (temp && temp->citizen != citizen) {
    /*
      在remove函数中，第一个版本的逻辑有问题。循环条件中，while (temp->citizen
      != citizen && temp)，
      这会导致在temp为nullptr时访问temp->citizen，从而引发段错误。正确的应该是先检查temp是否存在，
      即while (temp && temp->citizen != citizen)。
      而第二个版本使用了prev和current指针，循环条件是current && current->citizen
      != citizen，这样更安全，避免了空指针访问。
  */

    temp = temp->next;
    sec = sec->next;
    /* code */
  }
  if (temp) {
    sec->next = temp->next;
    if (temp == rear) rear = sec;
    delete temp;
    return;
  }
}
// 说明：从队列中移除指定的元素 citizen。
/* 你的代码将会被嵌入在这个位置 */

int main() {
  int caseCount = 0;
  int P, C;
  while (std::cin >> P >> C) {
    if (P == 0 && C == 0) {
      break;
    }

    caseCount++;
    std::cout << "Case " << caseCount << ":" << std::endl;

    Queue queue;
    for (int i = 1; i <= (P < C ? P : C); i++) {
      queue.enqueueRear(i);
      std::cout << "r2" << i << std::endl;
    }

    int citizen;
    for (int i = 0; i < C; i++) {
      char command;
      std::cin >> command;
      if (command == 'N') {
        citizen = queue.dequeue();
        std::cout << citizen << std::endl;
        queue.enqueueRear(citizen);
      } else if (command == 'E') {
        int x;
        std::cin >> x;
        queue.remove(x);
        queue.enqueueFront(x);
      }
    }
  }

  return 0;
}