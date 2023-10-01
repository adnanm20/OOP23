// Napisati program koji trazi od korisnika unos broja
// te ukoliko je broj djeljiv sa 3 na ekranu ispisuje Fizz,
// ukoliko je broj djeljiv sa 5 na ekranu ispisuje Buzz
// te ukoliko je broj djeljiv i sa 3 i sa 5, na ekranu se
// ispisuje FizzBuzz. Program se terminira kada korisnik 
// unese 0.


#include <iostream>

int main() {
  int x;

  while(x!=0)
  {
    std::cout << "Unesi cijeli broj" << std::endl;
    std::cin >> x;

    if(x%3==0) {
      std::cout << "Fizz";
    }

    if(x%5==0)
      std::cout << "Buzz";

    std::cout << std::endl;
  }
  return 0;
}
