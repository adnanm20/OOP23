#pragma once
#include<string>
#include<vector>
#include<list>
#include<iterator>
#include "Predmet.hpp"
#include "OcjenaIzPredmeta.hpp"

struct Student {
  std::string brojIndeksa;
  std::string ime;
  std::string prezime;
  std::string grad;
  std::vector<OcjenaIzPredmeta> ocjene;

  Student& promijeniBrojIndeksa();
  Student& promijeniIme();
  Student& promijeniPrezime();
  Student& promijenigrad();
  Student& dodajOcjenu(std::list<Predmet>::const_iterator);
  Student& izbrisiOcjene();
};



