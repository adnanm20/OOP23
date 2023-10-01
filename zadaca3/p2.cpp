#include<iostream>
#include<list>
#include<functional>

using namespace std;

list<int> partition(list<int>::const_iterator k, list<int>::const_iterator l, function<bool(int)> pred)
{
  list<int> t;
  while(k != l)
  {
    if(pred(*k))
    {
      t.push_front(*k);
    }
    else
    {
      t.push_back(*k);
    }
    k++;
  }
  return t;
}

int main(void)
{
  list<int> nums{15,20,25,-10,-75,100,-255,430,200};
  auto result = partition(nums.cbegin(), nums.cend(), [](int num) {return !(num % 2);});

  for(auto a : result)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
