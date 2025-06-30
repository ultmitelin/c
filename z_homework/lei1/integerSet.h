#ifndef INTEGERSET_H_INCLUDED
#define INTEGERSET_H_INCLUDED
class integerSet {
 private:
  int* a;
  unsigned cap, sz;

 public:
  //   void sort1(integerSet b) { sort(b.a, b.a + sz); }
  struct bad_integerSet {
    int errnum;
    bad_integerSet(int n = 0) { errnum = n; }
  };
  integerSet(unsigned c = 0) {
    sz = 0;
    cap = c;
    a = new int[cap];
  }
  integerSet(const integerSet& s) {
    sz = s.sz;
    cap = s.cap;
    a = new int[cap];
    for (unsigned int i = 0; i < cap; i++) a[i] = s.a[i];
  }
  ~integerSet() { delete[] a; }

  void clear() { sz = 0; }
  unsigned size() const { return sz; }
  unsigned capacity() const { return cap; }
  bool isEmpty() const { return sz == 0; }

  void print() const;
  void insert(int);
  integerSet setunion(const integerSet&) const;
  integerSet setintsection(const integerSet&) const;
  integerSet setdifference(const integerSet&) const;
  integerSet setsymmetricdifference(const integerSet& s) const;
  void erase(int);

  bool isMember(int) const;
  bool isSubset(const integerSet&) const;
  integerSet& operator=(const integerSet& s);
};

#endif  // INTEGERSET_H_INCLUDED
