#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <initializer_list>

#include "Lista.hpp"
#include "doctest.h"

TEST_CASE("Expects to construct empty list") {
  Lista lista;
  CHECK_EQ(lista.size(), 0);
  CHECK_EQ(lista.empty(), true);
}
TEST_CASE("Expects to add new element on the end of the list") {
  Lista lista;
  lista.push_back(1);
  CHECK_EQ(lista.back(), 1);
}

TEST_CASE("Expects to add new element on the begin of the list") {
  Lista lista;
  lista.push_front(-2);
  CHECK_EQ(lista.front(), -2);
}

TEST_CASE("Expects to create new list copying existing list") {
  Lista lista;
  for (auto i = 0u; i < 10; ++i) {
    lista.push_back(i);
  }
  CHECK_EQ(lista.size(), 10);
  Lista lista2 = lista;
  CHECK_EQ(lista2.size(), lista.size());
  CHECK_EQ(lista == lista2, true);
}

TEST_CASE("Expects to copy existing list with op=") {
  Lista lista;
  for (auto i = 0u; i < 10; ++i) {
    lista.push_front(i);
  }
  CHECK_EQ(lista.size(), 10);
  Lista lista2;
  lista2 = lista;
  CHECK_EQ(lista2.size(), lista.size());
  CHECK_EQ(lista == lista2, true);
}

TEST_CASE("Expects to pop all elements from the list") {
  Lista lista;
  for (auto i = 0u; i < 10; ++i) {
    lista.push_front(i);
  }
  CHECK_EQ(lista.size(), 10);
  for (auto i = 0u; i < 10; ++i) {
    lista.pop_back();
  }
  CHECK_EQ(lista.empty(), true);
}

TEST_CASE("Expects to extend list with other list") {
  Lista lista1;
  for (auto i = 0u; i < 10; ++i) {
    lista1.push_back(i);
  }

  Lista lista2;
  for (auto i = 10u; i < 20; ++i) {
    lista1.push_back(i);
  }
  lista1.extend(lista2);
  for (auto i = 0u; i < 20; ++i) {
    CHECK_EQ(lista1.front(), i);
    lista1.pop_front();
  }
}

