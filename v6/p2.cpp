// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci vektore i std::sort.
//
// Primjer:
//     Unesite rijeci:
//     hi
//     jedan
//     hi
//     dva
//     dva
//     tri
//     hi
//     vjezbe
//     vjezbe
//
//     Frekvencija ponavljanja:
//     dva: 2
//     hi: 3
//     jedan: 1
//     tri: 1
//     vjezbe: 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  string rijec;
  vector<string> rijeci;

  while(cin >> rijec)
  {
    rijeci.push_back(rijec);
  }

  sort(rijeci.begin(), rijeci.end());

  int br = 1;
  string t = rijeci.at(0);
  for(int i = 1; i < rijeci.size(); i++)
  {
    if(rijeci[i] == t)
    {
      br++;
    }
    else
    {
      cout << t << ": " << br << endl;
      br = 1;
      t = rijeci[i];
    }
  }
  
  cout << t << ": " << br << endl;

  return 0;
}
