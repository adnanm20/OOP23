#include<iterator>
#include<list>
#include<iostream>
#include<limits>
#include "Student.hpp"
#include "Predmet.hpp"
#include "OcjenaIzPredmeta.hpp"
#include "trazenje.cpp"

Student& Student::promijeniBrojIndeksa() {
  std::string s;
  std::cout << "Unesi novi indeks studenta: ";
  std::cin >> s;
  brojIndeksa = s;
  return *this;
}

Student& Student::promijeniIme() {
  std::string s;
  std::cout << "Unesi novo ime studenta: ";
  getline(std::cin, s);
  ime = s;
  return *this;
}

Student& Student::promijeniPrezime() {
  std::string s;
  std::cout << "Unesi novo prezime studenta: ";
  getline(std::cin, s);
  prezime = s;
  return *this;
}

Student& Student::promijenigrad() {
  std::string s;
  std::cout << "Unesi novi grad studenta: ";
  getline(std::cin, s);
  grad = s;
  return *this;
}

Student& Student::dodajOcjenu(std::list<Predmet>::const_iterator predmetIt) {
  auto oc = trazenje::pronadiPrvog(ocjene.begin(), ocjene.end(), 
      [predmetIt](OcjenaIzPredmeta o){if(o.predmet == predmetIt) return true; else return false;});

  if(oc != ocjene.end())
  {
    char c;
    std::cout << "Ocjena za ovaj predmet je vec upisana, zelite li je promijeniti? (y/n)" << std::endl;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(c == 'n')
    {
      return *this;
    }

    if(c == 'y')
    {
      int ocjena = 0;

      std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
      std::cin >> ocjena;
      while(ocjena < 5 || ocjena > 10)
      {
        std::cout << "Nevalidna ocjena!" << std::endl;
        std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
        std::cin >> ocjena;
      }

      oc->ocjena = ocjena;
    }
  }
  else
  {
    int ocjena = 0;

    std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
    std::cin >> ocjena;
    while(ocjena < 5 || ocjena > 10)
    {
      std::cout << "Nevalidna ocjena!" << std::endl;
      std::cout << "Unesi ocjenu za predmet " << predmetIt->naziv << ": ";
      std::cin >> ocjena;
    }

    OcjenaIzPredmeta op;
    op.ocjena = ocjena;
    op.predmet = predmetIt;
    ocjene.push_back(op);

    return *this;
  }

  return *this;
}

Student& Student::izbrisiOcjene() {
  ocjene.clear();
  return *this;
}
