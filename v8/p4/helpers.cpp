#include "helpers.hpp"
#include <iostream>

namespace vjezbe08 {

void print(const Cplx& cplx) {
  // your code here
  if(cplx.im >= 0)
  {
    std::cout << cplx.re << "+" << cplx.im << "i" << std::endl;
  }
  else
  {
    std::cout << cplx.re << cplx.im << "i" << std::endl;
  }
}

}
