#include<iostream>
#include<vector>
#include<string>


using namespace std;
struct radnik{
    
    string ime;
    double plata;
    int godine;
};

struct A{
    vector<radnik>baza;

  auto& unos(istream&);
  ostream&ispis(ostream&);
  bool fja(string &);
  double prosjek_plata();
  double prosjek_godina();
};
bool A::fja(string& ime1){
    for(auto el:baza){
        if(el.ime==ime1){
            
            throw domain_error{"Radnik vec u bazi"};
        }
        
    }
}

auto& A::unos(istream& ulaz){
    radnik a;
    while(ulaz>>a.ime>>a.plata>>a.godine) {
        try{if(fja(a.ime));
            baza.push_back(a);
        }
        catch(const domain_error &e){
            ulaz<<e.what()<<endl;
           
        }
    }
   
   
   
    return baza;

}
ostream &A::ispis(ostream& is){
    is<<"Ispis baze radnika: "<<endl;
    for(auto el:baza){
        is<< el.ime<<' '<<el.plata<< ' ' <<el.godine<<endl;
    }
    return is;
} 
double A::prosjek_plata(){
    double prosjek=0;
    double suma=0;
    auto i=0;
    for(auto el:baza){
        suma+=el.plata;
        ++i;
    }
    prosjek=suma/i;
    return prosjek;
    
}
double A::prosjek_godina(){
    double prosjek=0;
    double suma=0;
    auto i=0;
    for(auto el:baza){
        suma+=el.godine;
        ++i;
    }
    prosjek=suma/i;
    return prosjek;
    
}

int main(){
    A r;
    r.unos(cin);
    r.ispis(cout);
    cout<<"Prosjek plata je:"<<r.prosjek_plata()<<endl;
    cout<<"Prosjek godina je:"<<r.prosjek_godina()<<endl;
    return 0;
}