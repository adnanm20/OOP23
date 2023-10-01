#include <iostream>
using namespace std;

class A {
  public:
    A() {cout << 1;};
    A(int n) : n_(n) {cout << 2;};
    ~A() {cout << n_;};
    int n_ = 13;
};

class B {
  public:
    B() {cout << 3;};
    B(int) : a() {cout << 4;};
    ~B() {cout << 9;};
    A a = 4;
};

class C {
  public:
    C() : b2(1), b1() {cout << 5;};
    C(double) {cout << 6;};
    ~C() {cout << 8;};
    B b1 = 3;
    B b2;
};

int main(void)
{
  C c1(1);
  C c2;
  return 0;
}

//1
//4
//2
//3
//6
//2
//3
//1
//4
//5
//destr
//8prvo tijelo
//9
//13
//9
//4
//8xxx prvo tijelo
//8 prvo tijelo
//9
//4
//9
//13
//8xxx prvo tijelo
