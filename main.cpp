#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>

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
bool Patikrinimas(string kint, int m, int n);

int main(){

    int n, m;
    Mokinys A[CMax], B[CMax];
    int DID[CMax];
    string kint;

    cout << "Mokiniu skaicius: ";
    cin >> m;
    if(m == 0){ 
            cout << "Mokiniu nera arba ivestas netinkamas simbolis" << endl;
            return 0;
    }
    cout<<endl;
    cout << "Namu darbu skaicius: ";
    cin >> n;
    if(n == 0){ 
            cout << "Bandoma dalinti is nulio arba ivestas netinkamas simbolis" << endl;
            return 0;
    }
    cout << endl;
    cout << "Iveskite varda, pavarde, pazymius uz namu darbus bei egzamino rezultata: ";

    for(int i=0; i<m; i++){
        cin >> A[i].vardas >> A[i].pavarde;
        if(Patikrinimas(A[i].vardas, m,n) == false || Patikrinimas(A[i].pavarde, m,n) == false){
            cout << "Ivestas netinkamas vardas arba pavarde" <<endl;
            return 0;
        }
        for(int j=0; j<n; j++){
            cin >> A[i].ND[j];
            B[i].ND[j]=A[i].ND[j];
        }
        cin >> A[i].egzaminas;
        B[i].ND[n] = A[i].egzaminas; 
    }

    Vidurkis(A, n, m);

    cout<<endl;
    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)"<<endl;
    cout << setfill('-') << setw(80) << " " << endl;
    cout << setfill(' ');

    double MED[CMax];

    for(int i=0; i<m; i++){
        sort(B[i].ND, B[i].ND + (n+1));
        if((n+1)%2==0)
            MED[i] = (double) (B[i].ND[(n+1)/2 - 1] + B[i].ND[(n+1)/2]) / 2.0;
        else
            MED[i] = B[i].ND[(n+1)/2];
    }
    
    for(int i = 0; i<m; i++){
        cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << VID[i] << setw(18) << right << MED[i] << endl;
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
bool Patikrinimas(string kint, int m, int n){
    const int ilgis = kint.length();
    char* temp_array = new char[ilgis + 1];
    strcpy(temp_array, kint.c_str());
        for(int i=0; i<ilgis; i++){
            if(!isalpha(temp_array[i]))
                return false;
        }
    return true;
}