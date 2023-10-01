#include <iostream>

using namespace std;

struct A {
  A() {cout << 0;};
  A(int) {cout << 3;};
  A(const A& a) {cout << 1;};
  A(A&& a) {cout << 2;};
};

void foo(A&& a) {
  A b(a);
};

int main(void)
{
  foo(4);
  return 0;
}
