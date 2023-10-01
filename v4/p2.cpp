// Napisati program koji trazi unos decimalnog broja,
// te brise sve 0 iza zareza unesenog broja. Ukoliko
// su iza zareza sve nule program treba da izbrise i
// decimalnu tacku.
//
// Primjeri:
// Unesite broj: 5.41000
// 5.41
//
// Unesite broj: 5
// 5
//
// Unesite broj: 5.00000
// 5

#include <iostream>
#include <string>
int main (int argc, char *argv[]) {
  std::string num;
  std::cout << "Unesite broj: ";
  std::cin >> num;

  return 0;
}
