// Napisati funkciju koja uzima vektor stringova te 
// ga transformise na nacin da provjerava da li string
// zavrsava nekim od znakova interpunkcije koji oznacava
// kraj recenice (? ! ili .). Ukoliko string ne zavrsava
// nekim od znakova interpunkcije, dodati tacku na kraj 
// stringa.
//

#include <iostream>
#include <vector>

// implementacija funkcije
void dodaj(std::vector<std::string>& vec)
{
  for(int i = 0; i < vec.size(); i++)
  {
    if(vec[i].back() != '?' && vec[i].back() != '!' && vec[i].back() != '.')
    {
      vec[i].push_back('.');
    }
  }
}

int main (int argc, char *argv[])
{
  std::vector<std::string> vec;
  std::string input;
  while (std::getline(std::cin, input)) {
    vec.push_back(input);
  }
  // pozvati funkciju
  dodaj(vec);

  for(int i = 0; i < vec.size(); i++)
  {
    std::cout << vec[i] << std::endl;
  }
  // ispisati sve transformisane elemente

  return 0;
}
