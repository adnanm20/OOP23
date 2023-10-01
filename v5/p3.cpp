// Napisati program koji od korisnika trazi unos broja recenica.
// Nakon toga korisnik unosi onoliko recenica koliko je naveo,
// te program ispisuje prosjecnu duzinu unesenih recenica.
//
// Primjer:
// Unesite broj recenica: 3
// Unesite recenicu (1/3): Hello world
// Unesite recenicu (2/3): Danas je srijeda 
// Unesite recenicu (3/3): Hi
// Prosjecna duzina recenica: 9.66667


#include <iostream>

int main (int argc, char *argv[]) {
  int n; double sum = 0.;
  std::string s;
  std::cout << "Unesite broj recenica: " << std::endl;
  std::cin >> n;

  std::cin.ignore();
  for(int i = 0; i < n; i++)
  {
    std::cout << "Unesite recenicu (" << i+1 << '/' << n << "): ";
    getline(std::cin, s);
    sum = sum + s.size();
  }

 std::cout << "Prosjecna duzina recenica: " << sum / n << std::endl;

  return 0;
}
