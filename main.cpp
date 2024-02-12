#include <iostream>
#include <iomanip>

using namespace std;
const int CMax = 10;
double VID[CMax] ={0};

struct Mokinys{
  string vardas;
  string pavarde;
  int ND[CMax];
  int egzaminas;
};

void Vidurkis(Mokinys A[], int n, int m);

int main(){
    int n, m;
    Mokinys A[CMax];
    cout << "Mokiniu skaicius: ";
    cin >> m;
    cout<<endl;
    cout << "Namu darbu skaicius: ";
    cin >> n;
    cout << endl;
    cout << "Iveskite varda, pavarde, pazymius uz namu darbus bei egzamino rezultata: ";

    for(int i=0; i<m; i++){
        cin >> A[i].vardas >> A[i].pavarde;
        for(int j=0; j<n; j++){
            cin >> A[i].ND[j];
        }
        cin >> A[i].egzaminas;
    }

    Vidurkis(A, n, m);

    cout<<endl;
    cout << "Pavardė" << setfill(' ') << setw(10) << "Vardas" << setfill(' ') << setw(35) << "Galutinis (Vid.) / Galutinis(Med.)"<<endl;
    cout << "------------------------------------------"<<endl;
    
    for(int i = 0; i<m; i++){
        cout << A[i].vardas << setw(10) << A[i].pavarde << setw(10) << " " << endl;
    }
    return 0;
}
void Vidurkis(Mokinys A[], int n, int m){
    double suma = 0;
    for(int i=0; i<m; i++){
        for(int j = 0; j<n; j++)
            suma += A[i].ND[j];
        suma += A[i].egzaminas;
        VID[i] = suma / (n+1);
        suma = 0;
    }
}