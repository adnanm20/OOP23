// Napisati program koji trazi od korisnika unos rijeci
// te ispisuje unesene rijeci sortirane od Z -> A.

#include <iostream>
#include <algorithm>
#include <vector>



int main (int argc, char *argv[]) {
  std::vector<std::string> words;  

  std::string word;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> word) {
    words.push_back(word);
  }

  // vas kod ovde
  std::sort(words.begin(), words.end(), [](const std::string& p, const std::string& q) {return p > q;});


  for(int i = 0; i < words.size(); i++) {
    std::cout << words[i] << std::endl;
  }

  return 0;
}
