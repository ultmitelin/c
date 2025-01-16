#ifndef INTEGERSET_CPP
#define INTEGERSET_CPP
#include "integerSet.h"

#include <algorithm>
#include <iostream>
using namespace std;
void integerSet::print() const {
  for (int i = 0; i < this->sz; i++) cout << a[i] << " ";
};
void integerSet::erase(int a) {
  for (int i = 0; i < sz; i++) {
    if (this->a[i] == a) {
      for (int j = i; j < sz; j++) {
        this->a[j] = this->a[j + 1];
      }
      this->a[sz - 1] = '\0';
      sz--;
    }
  }
}
bool integerSet::isMember(int x) const {
  for (int i = 0; i < sz; i++) {
    if (this->a[i] == x) {
      return true;
    }
  }
  return false;
};
void integerSet::insert(int x) {
  this->a[sz++] = x;
  if (sz > cap) {
    throw bad_integerSet(x);
  }
};
integerSet integerSet::setunion(const integerSet& s2) const {
  int sz1 = this->sz;
  for (int i = 0; i < s2.sz; i++) {
    bool flag = true;
    for (int j = 0; j < this->sz; j++) {
      if (this->a[j] == s2.a[i]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      this->a[sz1++] = s2.a[i];
    }

    // this->sz=sz1;
  }
  integerSet temp;
  for (int i = 0; i < sz1; temp.a[i] = this->a[i], i++);
  temp.sz = sz1;
  temp.cap = INT_MAX;
  sort(temp.a, temp.a + sz1);
  return temp;
};
integerSet integerSet::setintsection(const integerSet& s2) const {
  integerSet temp;
  int k = 0;
  int sz1 = this->sz;
  for (int i = 0; i < s2.sz; i++) {
    bool flag = true;
    for (int j = 0; j < this->sz; j++) {
      if (s2.a[i] == this->a[j]) {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      temp.a[k++] = s2.a[i];
    }
    // this->sz=sz1;
  }

  // for (int i = 0; i < sz1; temp.a[i] = this->a[i], i++);
  temp.sz = k;
  temp.cap = INT_MAX;
  sort(temp.a, temp.a + k);
  return temp;
};
integerSet integerSet::setdifference(const integerSet& s2) const {
  integerSet temp(*this);
  for (int i = 0; i < this->sz; i++) {
    if (s2.isMember(this->a[i])) temp.erase(this->a[i]);
  }
  // 如果用temp.erase(temp.a[i]);，会改变temp各个数字下标，导致没删完整，所以不对
  temp.cap = INT_MAX;
  return temp;
};
integerSet integerSet::setsymmetricdifference(const integerSet& s) const {
  integerSet cp(*this);
  integerSet un{cp.setunion(s)};
  integerSet in{cp.setintsection(s)};
  integerSet temp{un.setdifference(in)};
  return temp;
};
inline bool integerSet::isSubset(const integerSet& other) const {
  integerSet temp(*this);
  int flag = 1;
  for (unsigned i = 0; i < other.sz; ++i) {
    if (temp.isMember(other.a[i])) {
      flag = 1;
      continue;
    }
    flag = 0;
    break;
  }
  if (flag) {
    return true;
  }
  return false;
}

inline integerSet& integerSet::operator=(const integerSet& other) {
  if (this != &other) {
    delete[] a;
    cap = other.cap;
    sz = other.sz;
    a = new int[cap];
    std::copy(other.a, other.a + sz, a);
  }
  return *this;
}

#endif