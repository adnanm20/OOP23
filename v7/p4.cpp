#include <iostream>
#include <vector>
#include <stdexcept>

int main(void)
{
  std::vector<std::string> vek{"dva", "elementa"};
  try {
    auto elem = vek.at(2);
  }
  catch(std::invalid_argument& err) {
    std::cout << "Invalid argument caught: " << err.what() << std::endl;
  }
  catch(std::out_of_range& err) {
    std::cout << "Out of range caught: " << err.what() << std::endl;
  }

  return 0;
}
