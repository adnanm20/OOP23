#include<iostream>
#include<vector>
#include<functional>

using namespace std;

typedef std::vector<std::function<bool(int)>> Funkcije;
void default_if_not_all(std::vector<int>& v, Funkcije f, int def=-1)
{
  for(auto& b : v)
  {
    for(auto p : f)
    {
      if(!p(b))
      {
        b = def;
      }
    }
  }
}

int main(void)
{
  Funkcije f = {[](int a){return a > 0;}, [](int a){return !(a%2);}, [](int a){return a < 100;}};
  // vector<int> v = {15, 20, 25, -10, -75, 100, -255, 430, 200};
  vector<int> v = {1, 2, 3, 4, 5, 6};

  default_if_not_all(v, f, 5);

  for(auto a : v)
  {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
