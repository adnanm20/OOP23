// Napisati program koji trazi unos broja od korisnika te
// ispisuje da li je broj paran ili neparan. 
#include <iostream>

int main() {
  int x;
  std::cout << "Unesi cijeli broj: " << std::endl;
  std::cin >> x;
  if(x%2) std::cout << "Nije paran" << std::endl;
  else std::cout << "Jest paran" << std::endl;

  return 0;
}
