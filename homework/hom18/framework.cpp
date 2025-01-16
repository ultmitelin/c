// framework.cpp
#ifndef FRAM
#define FRAM
#include <fstream>
#include <iostream>
using namespace std;
#include "framework.h"

int main_loop(Filter* p) {
  p->start();
  while (p->read()) {
    p->compute();
    p->write();
  }
  return p->result();
}

#endif