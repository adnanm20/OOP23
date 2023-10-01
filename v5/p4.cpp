// Napisati program koji trazi od korisnika unos brojeva.
// Unos se zavrsava kada korisnik unese "EOF" karakter.
// Program treba prvo da ispise sve unesene brojeve,
// te nakon toga da ispise samo one brojeve koji zadovoljavaju
// sljedeci uslov:  v[n-1] > v[n] < v[n+1]
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> v;
  int n;

  while(cin >> n)
  {
    v.push_back(n);
  }

  for(int i = 1; i < v.size()-1; i++)
  {
    if(v[i] < v[i-1] && v[i] < v[i+1])
    {
      std::cout << v[i] << " ";
    }
  }
  
  std::cout << std::endl;

  return 0;
}
