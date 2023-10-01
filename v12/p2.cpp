#include <iostream>

using namespace std;

int main(void)
{
  int a = 4;
  //ternarni operator ce biti rvalue ako je barem jedan od rezultatnih izraza rvalue
  const int& ref = (a==4) ? a : 7;
  a = 9;
  cout << a << ref << endl;
  return 0;
}
