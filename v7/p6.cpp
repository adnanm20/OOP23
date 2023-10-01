#include<iostream>
#include<functional>

int main() {
  std::function<bool(int, float)> f;
  // f(3, 4.0f);
  try {
    f(3, 4.0f);
  }
  catch(std::exception& e){
    std::cout << e.what() << std::endl;
  }

  return 0;
}
