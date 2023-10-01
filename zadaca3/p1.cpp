#include<iostream>
#include<list>
#include<iterator>

using namespace std;

list<int> parni_neparni(list<int>::const_iterator k, list<int>::const_iterator l)
{
  list<int> t;
  while(k != l)
  {
    *k%2 ? t.push_back(*k) : t.push_front(*k);
    k++;
  }
  return t;
}

int main(void)
{
  list<int> l = {25, 345, 234, 52, 36, 324, 5, 26, 324, 5, 2, 46, 2, 34, 63452, 1436};
  list<int> k = parni_neparni(l.cbegin(), l.cend());

  for(auto a : k)
  {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
