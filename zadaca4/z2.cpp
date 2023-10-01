#include <iostream>
#include <initializer_list>
#include <exception>
#include "MojNizInt.hpp"

using namespace std;

void print(const MojNizInt& m)
{
  for(size_t i = 0; i < m.size(); ++i)
  {
    cout << m.at(i) << " ";
  }
  cout << endl;
}

int main(void)
{
  MojNizInt x{1, 2, 3, 4, 5, 6};
  print(x);
  MojNizInt y{x*5};
  print(y);
  MojNizInt z;
  z = y;
  print(z);
  z = MojNizInt{2, 4, 6, 8, 10};
  print(z);
  print(y+x);
  print(y++);
  print(++y);
  y.push_back(24);
  print(y);
  
  return 0;
}
