#include<functional>
#include<vector>
// #include "trazenje.hpp"

namespace trazenje {
  template<typename T>
  T pronadiPrvog(T k, T l, std::function<bool(typename T::value_type)> pred) {
    while(k != l)
    {
      if(pred(*k)) return k;
      ++k;
    }
    return l;
  }

  template<typename T>
  std::vector<typename T::value_type> pronadiSve(T k, T l, std::function<bool(typename T::value_type)> pred) {
    std::vector<typename T::value_type> vec;
    while(k != l)
    {
      if(pred(*k)) vec.push_back(*k);
      ++k;
    }
    return vec;
  }
}
