#include "LongNumber.hpp"
#include  <iostream>

using namespace std;

using namespace Types;

int main(void)
{
  Types::LongNumber l1;
  cout << "l1 " << l1 << endl;
  Types::LongNumber l2{25};
  cout << "l2 " << l2 << endl;
  Types::LongNumber l3{l2};
  cout << "l3 " << l3 << endl;
  Types::LongNumber l4{l2+l3};
  cout << "l4 " << l4 << endl;

  long long int x = 1231;
  Types::LongNumber l5{x};
  cout << "l5 " << l5 << endl;
  Types::LongNumber l6{l2 + x};
  cout << "l6 " << l6 << endl;

  l6 = 123;
  cout << "l6 " << l6 << endl;
  l6 += 10;
  cout << "l6 " << l6 << endl;
  l6 -= 20;
  cout << "l6 " << l6 << endl;
  l6 *= 2;
  cout << "l6 " << l6 << endl;
  l6 /= 10;
  cout << "l6 " << l6 << endl;
  cout << "l6 - l5 " << l6 - l5 << endl;
  cout << "l6 * l2 " << l6 * l2 << endl;
  cout << "l6 / l2 " << l6 / l2 << endl;
  l6 = l2;
  cout << "l6 " << l6 << endl;
  l6 += l2;
  cout << "l6 " << l6 << endl;
  l6 -= l2;
  cout << "l6 " << l6 << endl;
  l6 *= l2;
  cout << "l6 " << l6 << endl;
  l6 /= l3;
  cout << "l6 " << l6 << endl;
  Types::LongNumber l7;
  l7 = l6;
  cout << "l7 " << l7 << endl;
  l7 = Types::LongNumber{123};
  cout << "l7 " << l7 << endl;
  l7 = x;
  cout << "l7 " << l7 << endl;
  Types::LongNumber l8{10};
  Types::LongNumber l9{5};
  cout << l8 << "==" << l9 << " " << (l8 == l9) << endl;
  cout << l8 << "!=" << l9 << " " << (l8 != l9) << endl;
  cout << l8 << ">" << l9 << " " << (l8 > l9) << endl;
  cout << l8 << "<" << l9 << " " << (l8 < l9) << endl;
  cout << l8 << ">=" << l9 << " " << (l8 >= l9) << endl;
  cout << l8 << "<=" << l9 << " " << (l8 <= l9) << endl;
  cout << l8 << "==" << x << " " << (l8 == x) << endl;
  cout << l8 << "!=" << x << " " << (l8 != x) << endl;
  cout << l8 << ">" << x << " " << (l8 > x) << endl;
  cout << l8 << "<" << x << " " << (l8 < x) << endl;
  cout << l8 << ">=" << x << " " << (l8 >= x) << endl;
  cout << l8 << "<=" << x << " " << (l8 <= x) << endl;
  short y = 2;
  cout << l8 << "^" << y << " " << (l8^y) << endl;
  if(l8)
    cout << l8 << endl;

  cout << l8++ << endl;
  cout << l8-- << endl;
  cout << ++l8 << endl;
  cout << --l8 << "\n" << endl;
  cout << l8.abs() << endl;
  cout << l8.isEven() << endl;
  cout << l8.isOdd() << endl;
  cout << l8.isPositive() << endl;
  cout << l8.isNegative() << endl;
  cout << l8.value() << endl;
  l8.num() = 35;
  cout << l8 << endl;
  return 0;
}
