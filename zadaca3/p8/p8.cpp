#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<functional>
#include<iomanip>
#include<limits>
#include "Student.hpp"
#include "Predmet.hpp"
#include "OcjenaIzPredmeta.hpp"
#include "trazenje.cpp"

void printStudentMenu() {
  std::cout << "1. Mijenjanje broja indeksa studenta" << std::endl;
  std::cout << "2. Mijenjanje imena studenta" << std::endl;
  std::cout << "3. Mijenjanje prezimena studenta" << std::endl;
  std::cout << "4. Mijenjanje grada studenta" << std::endl;
  std::cout << "5. Dodavanje novih ocjena studentu" << std::endl;
  std::cout << "6. Brisanje svih ocjena studenta" << std::endl;
  std::cout << "7. Izlaz" << std::endl;
}

void printMainMenu() {
  std::cout << "1. Dodavanje predmeta" << std::endl;
  std::cout << "2. Dodavanje studenta" << std::endl;
  std::cout << "3. Uredivanje studenta" << std::endl;
  std::cout << "4. Ispis studenata za predmet" << std::endl;
  std::cout << "5. Izlaz" << std::endl;
}

void dodajPredmet(std::list<Predmet>& predmeti) {
  std::string naziv, odsjek;
  std::cout << "Unesi naziv predmeta: " << std::endl;
  getline(std::cin, naziv);
  if(trazenje::pronadiPrvog(predmeti.cbegin(), predmeti.cend(), [naziv](Predmet p){ if(p.naziv == naziv) return true; else return false;}) != predmeti.cend())
  {
    std::cout << "Predmet vec postoji!" << std::endl;
    return;
  }
  std::cout << "Unesi odsjek: ";
  getline(std::cin, odsjek);
  Predmet pr;
  pr.naziv = naziv;
  pr.odsjek = odsjek;
  predmeti.push_back(pr);
}

void dodajStudenta(std::vector<Student>& studenti) {
  std::string brIndeksa, ime, prezime, grad;
  std::cout << "Unesite broj indeksa: ";
  std::cin >> brIndeksa;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if(trazenje::pronadiPrvog(studenti.cbegin(), studenti.cend(), [brIndeksa](Student s){ if(s.brojIndeksa == brIndeksa) return true; else return false;}) != studenti.cend())
  {
    std::cout << "Vec postoji student sa tim brojem indeksa!" << std::endl;
    return;
  }
  std::cout << "Unesi ime studenta: ";
  getline(std::cin, ime);
  std::cout << "Unesi prezime studenta: ";
  getline(std::cin, prezime);
  std::cout << "Unesi grad studenta: ";
  getline(std::cin, grad);
  Student s;
  s.brojIndeksa = brIndeksa;
  s.ime = ime;
  s.prezime = prezime;
  s.grad = grad;
  studenti.push_back(s);
}

void urediStudenta(std::vector<Student>& studenti, std::list<Predmet>& predmeti)
{
  std::string brIndeksa;
  std::cout << "Unesi broj indeksa studenta kojeg zelis da uredis: ";
  std::cin >> brIndeksa;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<Student>::iterator student = 
    trazenje::pronadiPrvog(studenti.begin(), studenti.end(), [brIndeksa](Student s){ if(s.brojIndeksa == brIndeksa) return true; else return false;});
  if(student == studenti.cend())
  {
    std::cout << "Ne postoji student sa tim brojem indeksa!" << std::endl;
    return;
  }
  
  int choice = 0;
  while(true)
  {
    printStudentMenu();
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch(choice) {
      case 1: {
        student->promijeniBrojIndeksa();
        break;
      }
      case 2: {
        student->promijeniIme();
        break;
      }
      case 3: {
        student->promijeniPrezime();
        break;
      }
      case 4: {
        student->promijenigrad();
        break;
      }
      case 5: {
        std::string pred;
        std::cout << "Unesite predmet za kojeg zelite dodati ocjenu: ";
        std::cin >> pred;
        std::list<Predmet>::const_iterator predIt = 
          trazenje::pronadiPrvog(predmeti.cbegin(), predmeti.cend(), [pred](Predmet p){ if(p.naziv == pred) return true; else return false;});
        if(predIt == predmeti.cend())
        {
          std::cout << "Taj predmet ne postoji!" << std::endl;
          return;
        }
        student->dodajOcjenu(predIt);
        break;
      }
      case 6: {
        student->izbrisiOcjene();
        break;
      }
      case 7:
        return;
      default:
        std::cout << "Nevalidan izbor!" << std::endl;
    }
  }
}

void ispisStudenataZaPredmet(std::vector<Student>& studenti, std::list<Predmet>& predmeti) {
  std::string predmet;
  std::cout << "Unesi naziv predmeta za koji zelis ispis: ";
  getline(std::cin, predmet);
  std::list<Predmet>::const_iterator predIt = 
    trazenje::pronadiPrvog(predmeti.cbegin(), predmeti.cend(), [predmet](Predmet p){ if(p.naziv == predmet) return true; else return false;});
  if(predIt == predmeti.cend())
  {
    std::cout << "Taj predmet ne postoji!" << std::endl;
    return;
  }

  std::vector<Student> vec = 
    trazenje::pronadiSve(studenti.begin(), studenti.end(), [predIt](Student s){
        return trazenje::pronadiPrvog(s.ocjene.begin(), s.ocjene.end(), [predIt](OcjenaIzPredmeta o){
              if(o.predmet == predIt) return true;
              else return false;
              }) != s.ocjene.end();});

  double prosjek = 0;
  for(auto& a : vec)
  {
    auto oc = trazenje::pronadiPrvog(a.ocjene.begin(), a.ocjene.end(), [predIt](OcjenaIzPredmeta o){
              if(o.predmet == predIt) return true;
              else return false;
              });
    prosjek += (double)oc->ocjena;
    std::cout << a.brojIndeksa << " " << a.ime << " " << a.prezime << " " << oc->ocjena << std::endl; 
  }
  std::cout << "Prosjek je: " << prosjek/vec.size() << std::endl;
}

int main()
{
  std::vector<Student> studenti;
  std::list<Predmet> predmeti;
  int choice = 0;
  while(true)
  {
    printMainMenu();
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch(choice) {
      case 1:
        dodajPredmet(predmeti);
        break;
      case 2:
        dodajStudenta(studenti);
        break;
      case 3:
        urediStudenta(studenti, predmeti);
        break;
      case 4:
        ispisStudenataZaPredmet(studenti, predmeti);
        break;
      case 5:
        return 0;
      default:
        std::cout << "Nevalidan izbor!" << std::endl;
    }
  }


  return 0;
}
