#include<iostream>

using namespace std;

struct A {
  A() = default;
  A(const A&) {cout << 1;};
  A(A&&) {cout << 2;};
};

void foo(A&& a) {
  A a1(std::move(a));
}

int main(void)
{
  foo(A());
  return 0;
}
