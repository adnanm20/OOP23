#include<iterator>
#include<functional>

namespace my {
  template<typename it>
  void sort(it, it);

  template<typename it>
  void sort(it, it, std::function<bool(typename it::value_type, typename it::value_type)>);
}
