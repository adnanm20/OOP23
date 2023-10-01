// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci std::map.
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
//
// Nakon dobijenog ispisa iznad, izvuci sve kljuceve mape u vektor
// koristeci std::transform iz algorithm zaglavlja te ispisati 
// sadrzaj vektora na ekran.
#include<iostream>
#include<map>
#include<string>
// #include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
  map<string, int> rijeci;
  string r;
  cout << "Unesite rijeci: " << endl;
  while(cin >> r)
  {
    rijeci[r]++;
  }

  vector<string> keys;
  transform(rijeci.begin(), rijeci.end(), back_inserter(keys), [](pair<string, int> el) {return el.first;});

  cout << "Frekvencija ponavljanja:" << endl;
  for(auto&& p : rijeci)
  {
    cout << p.first << ": " << p.second << endl;
  }
  for(auto&& k : keys)
  {
    cout << k << endl;
  }
  return 0;
}
