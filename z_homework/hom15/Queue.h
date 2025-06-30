#ifndef QUE_H
#define QUE_H
#include <iostream>
// #include <vector>
using namespace std;
class Queue {
 private:
  // vector<int> q;
  int *q;
  int sz, cap;

 public:
  Queue(int a = 0) {
    sz = 0;
    cap = a;
    q = new int[sz];
  };
  ~Queue() { delete[] q; };
  void enqueue(int a);
  int dequeue();
  int peek();
  bool isEmpty();
  bool isFull();
  int size();
  // void show() { for (int i = 0; i < sz; cout << q[i], i++); }
};

#endif