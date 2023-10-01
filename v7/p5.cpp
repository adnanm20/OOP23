// Napisati funkciju filter koja treba da isfiltrira proslijedjeni
// vektor na nacin da kopira elemente proslijedjenog vektora koji
// zadovoljavaju dati predicate. Ukoliko je proslijedjena nevalidna
// predicate funkcija, potrebno je baciti iznimku tipa:
//    std::logic_error
//
// Nakon toga, dodati jos jednu (overloaded) funkciju filter koja
// uzima vektor i string te kopira sve stringove koji odgovaraju
// datom argumentu u rezultujuci vektor.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>

std::vector<std::string> filter(const std::vector<std::string>& v,
                                std::function<bool(const std::string&)> predicate) {
  //
}

// overload goes here

int main (int argc, char *argv[])
{
  std::vector<std::string> vec;
  std::string s;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> s) {
    vec.push_back(s);
  }

  auto filtered = filter(vec, [](const std::string& s) {
    return s.size() > 5;
  });

  return 0;
}               
