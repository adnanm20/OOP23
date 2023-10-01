#include<iostream>
#include<list>
#include<functional>

using namespace std;

list<int> partition(list<int>::const_iterator k, list<int>::const_iterator l, function<bool(int)> pred)
{
  list<int> t;
  auto p = k;
  while(p != l)
  {
    try
    {
      if(pred(*p))
      {
        t.push_front(*p);
      }
      else
      {
        t.push_back(*p);
      }
      p++;
    }
    catch (int)
    {
      t.clear();
      while(k != l)
      {
        t.push_back(*k);
				k++;
      }
      return t;
    }
  }
  return t;
}

int main(void)
{
  list<int> nums{15,20,25,-10,-75,100,-255,430,200};
  auto result = partition(nums.cbegin(), nums.cend(), [](int num) { if (num > 400) throw 5; return num > 0; });

  for(auto a : result)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
