#pragma once
#include "Predmet.hpp"
#include<iterator>
#include<list>

struct OcjenaIzPredmeta {
  int ocjena;
  std::list<Predmet>::const_iterator predmet;
};
