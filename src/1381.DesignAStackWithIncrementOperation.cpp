#include "headers.h"

class CustomStack {
 public:
  std::vector<int> stack;
  int n;
  CustomStack(int maxSize) : n(maxSize) {}

  void push(int x) {
    if (stack.size() < n) {
      stack.push_back(x);
    }
  }

  int pop() {
    if (stack.size() == 0) return -1;
    int temp = stack.back();
    stack.pop_back();
    return temp;
  }

  void increment(int k, int val) {
    int i = 0;
    while (k-- && i < stack.size()) {
      stack[i] = stack[i] + val;
      i++;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
