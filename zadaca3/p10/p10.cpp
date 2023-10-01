#include<list>
#include<vector>
#include<iostream>
#include<iterator>
#include<functional>
#include<stdlib.h>
#include<algorithm>
#include<time.h>

#include "my.hpp"

int counter = 0;

template<typename iter>
void split(iter begin, iter end, iter& fs, iter& fe, iter& bs, iter&be)
{
  iter f = begin, s = begin;
  while(f != end)
  {
    ++f;
    ++s;
    if(f != end)
    {
      ++f;
    }
  }
  fs = begin;
  fe = s;
  bs = s;
  be = f;
}

template<typename it>
void my_sort(it begin, it end)
{
  my_sort(begin, end, [](typename it::value_type a, typename it::value_type b){ return a < b; });
}

template<typename it>
void my_sort(it begin, it end, 
    std::function<bool(typename it::value_type, typename it::value_type)> predicate)
{
  if(begin == end)
  {
    return;
  }

  if(begin == --end)
  {
    return;
  }
  ++end;

  if(++begin == --end)
  {
    --begin;
    if(!predicate(*begin, *end) && ++counter)
    {
      typename it::value_type c;
      c = *begin;
      *begin = *end;
      *end = c;
    }
    return;
  }
  else
  {
    --begin;
    ++end;
    it fls;
    it fle;
    it bls;
    it ble;
    split(begin, end, fls, fle, bls, ble);

    my_sort(fls, fle, predicate);
    my_sort(bls, ble, predicate);

    typename it::value_type c;
    it a = begin;
    while(bls != end)
    {
      // cout << "Comparing: " << *fls << " " << *bls << endl;
      if(!predicate(*fls, *bls) && ++counter)
      {
        c = *bls;
        *bls = *fls;
        *fls = c;
        ++fls;
      }
      else
      {
        ++fls;
      }

      if(fls == bls)
      {
        ++bls;
        fls = begin;
      }
    }
  }
}

int main(void)
{

  srand(time(NULL));
  std::list<int> l;
  for(int i = 0; i < 100000; i++)
  {
    l.push_back(rand() % 10000000);
  }
  std::cout << "Starting sort!" << std::endl;
  
  counter = 0;
  l.sort();
  std::cout << counter << std::endl;
  for(auto& a : l)
  {
    std::cout << a << " ";
  }
  std::cout << std::endl;






//faks lol
  // std::vector<int> v;
  // my_sort(begin(v), end(v));
  // std::vector<int> v{5};
  // my_sort(begin(v), end(v)); 
  // std::vector<int> v{5, 1};
  // my_sort(begin(v), end(v)); 
  // std::vector<int> v{5, 1, 5, 1};
  // my_sort(begin(v), end(v)); 
  // std::vector<int> v{0, 10, -8, 1, 18, -22};
  // my_sort(begin(v), end(v)); 
  // std::list<int> v{0, 10, -8, 1, 18, -8};
  // my_sort(begin(v), end(v), 
      // [](const auto& a, const auto& b){ return a > b;});
  // std::vector<std::string> v{"ako",  "p",   "onda", "q"};
  // my_sort(begin(v), end(v), 
      // [](const auto& a, const auto& b){ return a.size() >= b.size();});

  // for(auto&& a : v)
  // {
  //   std::cout << a << " ";
  // }
  // std::cout << std::endl;

  return 0;
}
