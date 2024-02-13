#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <conio.h>

using namespace std;
const int CMax = 10;
double VID[CMax] = {0};

struct Mokinys{
  string vardas;
  string pavarde;
  int namu_darbai;
  int egzaminas;
};

bool Patikrinimas(string kint);
void Vidurkis(Mokinys A[], int kiekis);

int main(){

    int n, m;
    Mokinys A[CMax], B[CMax];
    int DID[CMax];
    string kint;

    int temp=0;
    int kiekis = 0;
    char input;

    cout << "Irasykite vardus ir pavardes, paspauskite * jei norite baigti irasyma: " << endl;

    while(1){
        input = _getch();
        if(input == '*') break;
        cin >> A[temp].vardas >> A[temp].pavarde;
        temp++;
        kiekis++;
    }
    cout << "Irasykite namu darbu be egzamino pazymius, paspauskite * jei norite baigti irasyma: " << endl;

    temp = 0;
    int kiekis2=0;
    for(int i=kiekis; i>kiekis; i--){
    while(1){
        input = _getch();
        if (input == '*'){
            cout << "Irasykite egzamino rezultata: ";
            cin >> A[temp].egzaminas;
        }
        if(input == '*') break;
        cin >> A[temp].namu_darbai;
        temp++;
        }
    }

    for(int i=0; i<kiekis+1; i++){
        B[i].namu_darbai = A[i].namu_darbai;
        if(i = kiekis) B[i].namu_darbai = A[i].namu_darbai;
    }

    Vidurkis(B, kiekis);

    cout<<endl;
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)"<<endl;
    cout << setfill('-') << setw(80) << " " << endl;
    cout << setfill(' ');

    double MED[CMax];

    for(int i=0; i<m; i++){
        sort(B[i].namu_darbai, B[i].namu_darbai + (n+1));
        if((n+1)%2==0)
            MED[i] = (double) (B[(n+1)/2 - 1].namu_darbai + B[(n+1)/2].namu_darbai) / 2.0;
        else
            MED[i] = B[(n+1)/2].namu_darbai;
    }
    
     for(int i = 0; i<m; i++){
         cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << VID[i] << setw(18) << right << MED[i] << endl;
     }
     return 0;
}
void Vidurkis(Mokinys A[], int kiekis){
    double suma = 0;
    for(int i=0; i<kiekis; i++){
        suma += A[i].namu_darbai ;
        suma += A[i].egzaminas;
        VID[i] = suma / (kiekis );
        suma = 0;
    }
}
 bool Patikrinimas(string kint){
     const int ilgis = kint.length();
     char* temp_array = new char[ilgis + 1];
     strcpy(temp_array, kint.c_str());
         for(int i=0; i<ilgis; i++){
             if(!isalpha(temp_array[i]))
                 return false;
         }
     delete[] temp_array;
     return true;
}