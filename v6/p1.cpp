// Napisati program koji od korisnika trazi unos rijeci.
// Nakon toga unesenu rijec ispisuje na satrovackom. :)
//
// Primjer:
// Unesite rijec: nemoj
// mojne
//
// Unesite rijec: zdravo
// vozdra

#include <iostream>
#include <string>

using namespace std;

int find_vowel(const string& input)
{
  int prviSam = -1;

  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
    {
      prviSam = i;
      break;
    }
  }
  return prviSam;
}

string make_satr(const string& input, int index)
{
  string satr;
  for(int i = index + 1; i < input.length(); i++)
  {
    satr.push_back(input[i]);
  }
  for(int i = 0; i <= index; i++)
  {
    satr.push_back(input[i]);
  }
  return satr;
}

int main(void)
{
  string input;

  cout << "Unesite rijec: ";
  cin >> input;

  auto ind = find_vowel(input);
  
  if(ind == -1)
  {
    cout << input << endl;
    return 0;
  }

  auto satr = make_satr(input, ind);

  cout << satr << endl;

  return 0;
}
