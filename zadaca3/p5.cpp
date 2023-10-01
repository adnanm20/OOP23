#include<iostream>
#include<list>
#include<vector>
#include<functional>
#include<iterator>

using namespace std;

list<int> filter(list<int>& v, function<bool(int)> pred)
{
  list<int> a;
  for(auto& p : v)
  {
    if(pred(p))
    {
      a.push_back(p);
    }
  }
  return a;
}

template<typename T>
list<T> filter(list<T>& v, function<bool(T)> pred)
{
  list<T> a;
  for(auto& p : v)
  {
    if(pred(p))
    {
      a.push_back(p);
    }
  }
  return a;
}

template<typename T>
T filter(T& v, function<bool(typename T::value_type)> pred)
{
  T a;
  for(auto& p : v)
  {
    if(pred(p))
    {
      a.push_back(p);
    }
  }
  return a;
}

int main(void)
{
  list<int> cont = {1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
  list<double> cont1 = {1., 9., 8., 4., 11., 0., 2., 6., 15., 3., 10.};
  vector<int> v = {1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
  auto res1 = filter(cont, [](int n) { return (n%2) == 0; });
  auto res2 = filter(cont1, [](double n) { return ((int)n%2) == 0; });
  auto res3 = filter(v, [](int n) { return ((int)n%2) == 0; });
  for(auto a : res1)
  {
    cout << a << " ";
  }

  cout << endl;
  return 0;
}
