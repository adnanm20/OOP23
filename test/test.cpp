#include<iostream>
#include<string>
#include<iterator>

void func()
{
  throw 5;
}

int main()
{
  try
  {
    throw 4;
  }
  catch (int a)
  {
    std::cout << a << std::endl;
  }

  return 0;
}
