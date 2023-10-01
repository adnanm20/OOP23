#include <iostream>
using namespace std;

struct A {
  A() {cout << 1;};
  ~A() {cout << 7;};
};

int main(void)
{
  cout << 0;
  A();
  cout << 9;
  
  return 0;
}

//0179
