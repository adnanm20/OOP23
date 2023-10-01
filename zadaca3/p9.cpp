#include<iostream>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

template<typename T>
bool jednako(T p, T k, T l)
{
  while(p != k)
  {
    if(*p != *l)
    {
      return false;
    }
    p++;
    l++;
  }
  return true;
}

int main(void)
{
  string s;
  cout << "Unesi rijec: ";
  cin >> s;
  string b = s;
  reverse(b.begin(), b.end());
  if(jednako(s.begin(), s.end(), b.begin()))
  {
    cout << "Rijec je palindrom!" << endl;
  }
  else
  {
    cout << "Rijec nije palindrom!" << endl;
  }


  return 0;
}
