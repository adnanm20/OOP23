#pragma once
#include<functional>
#include<vector>

namespace trazenje {
  template<typename T>
  T pronadiPrvog(T k, T l, std::function<bool(typename T::value_type)> pred) {}

  template<typename T>
  std::vector<typename T::value_type> pronadiSve(T k, T l, std::function<bool(typename T::value_type)> pred) {}
}
