// Napisati program koji trazi od korisnika unos imena,
// a zatim na ekran ispisuje uokvireno ime sa praznim prostorom
// sirine 2 karaktera. 
//
// Primjer:
//
// Unesite ime: Mirza
// **********************
// **********************
// **                  **
// **                  **
// **  Pozdrav Mirza!  **
// **                  **
// **                  **
// **********************
// **********************
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
  string ime;
  std::cout << "Unesite ime: ";
  std::cin >> ime;

  string prvi(ime.size() + 17, '*');
  string drugi = "**" + string(ime.size() + 13, ' ') + "**";

  string poz = "**  Pozdrav " + ime + "!  **";

  string e = 
    prvi + '\n' + prvi + '\n' + 
    drugi + '\n' + drugi + '\n' + 
    poz + '\n' + 
    drugi + '\n' + drugi + '\n' + 
    prvi + '\n' + prvi;

  std::cout << e << std::endl;
  
  return 0;
}
