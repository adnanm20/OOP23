class A {
  A() = default;
  A(int) {}
}

void foo(A a) {
  cout << 1 << endl;
}

int main(void)
{
  foo(1);
  return 0;
}

//Da li ovaj kod kompajlira?
//Da
//3 koraka pronalazenja funkcije + u A je omogucena implicitna konverzija
//sprijeciti sa explicit linija 3
