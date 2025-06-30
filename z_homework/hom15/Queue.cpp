#ifndef QUE_CPP
#define QUE_CPP
#include "Queue.h"

#include <vector>
void Queue::enqueue(int a) {
  if (sz < cap) {
    if (sz == 0) {
      q[0] = a;
    } else {
      for (int i = sz; i > 0; i--) {
        q[i] = q[i - 1];
      }
      q[0] = a;
    }
    sz++;
  } else {
    string s = "Full";
    throw s;
  }
};
int Queue::dequeue() {
  if (sz > 0) {
    int x = q[0];
    for (int i = 0; i < sz - 1; q[i] = q[i + 1], i++);
    sz--;
    return x;
  } else {
    string s = "Empty";
    throw s;
  }
}
int Queue::peek() {
  if (sz > 0) {
    return q[0];
  } else {
    string s1 = "Empty";
    throw s1;
  }
}
bool Queue::isEmpty() {
  if (sz == 0) {
    return true;
  } else
    return false;
}
bool Queue::isFull() {
  if (sz == cap) {
    return true;
  } else
    return false;
}
int Queue::size() { return sz; }

#endif