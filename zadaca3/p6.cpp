#include<iostream>
#include<list>
#include<vector>
#include<functional>

using namespace std;

list<int> map(list<int>& l, function<int(int)> func)
{
  cout << 1 << endl;
  list<int> k;
  for(auto b : l)
  {
    k.push_back(func(b));
  }
  return k;
}

template<typename T>
list<T> map(list<T>& l, function<T(T)> func)
{
  cout << 2 << endl;
  list<T> k;
  for(auto b : l)
  {
    k.push_back(func(b));
  }
  return k;
}

template<typename T>
T map(T& l, function<typename T::value_type(typename T::value_type)> func)
{
  cout << 3 << endl;
  T k;
  for(auto b : l)
  {
    k.push_back(func(b));
  }
  return k;
}

int main(void)
{
  list<int> l = {7, 2, -4, 5, 0, 6, 3};
  list<double> ld = {7., 2., -4., 5., 0., 6., 3.};
  vector<int> v = {7, 2, -4, 5, 0, 6, 3};
  auto result1 = map(l, [](int n){return n * 2 + 1;});
  auto result2 = map<double>(ld, [](double n){return n * 2 + 1;});
  auto result3 = map(v, [](int n){return n * 2 + 1;});
  for(auto a : result1)
  {
    cout << a << " ";
  }
  cout << endl;
  for(auto a : result2)
  {
    cout << a << " ";
  }
  cout << endl;
  for(auto a : result3)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
