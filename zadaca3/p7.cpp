#include<iostream>
#include<list>
#include<vector>
#include<functional>

using namespace std;

int reduce(list<int>& l, function<int(int, int)> func, int start = 0)
{
  for(auto b : l)
  {
    start = func(start, b);
  }
  return start;
}

template<typename T>
T reduce(list<T>& l, function<T(T, T)> func, T start = 0)
{
  for(auto b : l)
  {
    start = func(start, b);
  }
  return start;
}

template<typename T>
typename T::value_type reduce(T& l, function<typename T::value_type(typename T::value_type, typename T::value_type)> func, typename T::value_type start = 0)
{
  for(auto b : l)
  {
    start = func(start, b);
  }
  return start;
}
int main(void)
{
  list<int> l = {11, 4, 5, 12, 6, 8, 9};
  list<double> ld = {11., 4., 5., 12., 6., 8., 9.};
  vector<int> v = {11, 4, 5, 12, 6, 8, 9};
  auto result1 = reduce(l, [](int a, int b){return a + b + 1;}, -12);
  auto result2 = reduce<double>(ld, [](double a, double b){return a + b + 1;}, -12);
  auto result3 = reduce(v, [](int a, int b){return a + b + 1;}, -12);
  cout << result1 << " ";
  cout << result2 << " ";
  cout << result3 << " ";
  cout << endl;
  return 0;
}
