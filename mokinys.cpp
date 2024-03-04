#include "mokinys.h"

bool Patikrinimas(string kint)
{
    const int ilgis = kint.length();
    char *temp_array = new char[ilgis + 1];
    strcpy(temp_array, kint.c_str());
    for (int i = 0; i < ilgis; i++)
    {
        if (!isalpha(temp_array[i]))
            return false;
    }
    delete[] temp_array;
    return true;
}

void Vidurkis(vector<Mokinys> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        Mokinys &mok = A[i];
        double suma = 0;
        for (int pazymys : mok.ND)
        {
            suma += pazymys;
        }
        suma += mok.egzaminas;
        double vidurkis = suma / (mok.ND.size() + 1);
        mok.VID = vidurkis;
    }
}

bool PagalVidurki(const Mokinys &a, const Mokinys &b)
{
    return a.VID > b.VID;
}

bool PagalMediana(const Mokinys &a, const Mokinys &b)
{
    return a.MED > b.MED;
}

bool PagalVarda(const Mokinys &a, const Mokinys &b)
{
    return a.vardas > b.vardas;
}

bool PagalPavarde(const Mokinys &a, const Mokinys &b)
{
    return a.pavarde > b.pavarde;
}
void FailuGeneravimas(){
    ofstream fr(CRfv2);

    if(!fr.is_open())
        throw runtime_error("Failas nurodytoje vietoje neegzistuoja!");
    
    int nd;
    cout << "Iveskite namu darbu kieki: " << endl;
    cin >> nd;
    if(cin.fail())
        throw runtime_error("Namu darbai turi buti skaicius!");
    
    fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for(int i=0; i<nd; i++)
        fr << setw(10) << left << "ND";
    fr << setw(10) << left << "Egz." << endl;

    int irasai;
    cout << "Iveskite irasu skaiciu: " << endl;
    cin >> irasai;

    for(int j=1; j<=irasai; j++){
        fr << setw(20) << left << ("Vardas"+to_string(j)) << setw(20) << left << ("Pavarde"+to_string(j));
        for(int i=0; i<nd; i++)
            fr << setw(10) << left << rand()%10+1;
        fr << setw(10) << left << rand()%10+1 << endl;
    }
    fr.close();
    

}

void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis)
{
    char kint;
    cout << "Rezultatus matyti norite ekrane ar faile?(e/f): ";
    cin >> kint;
    if (kint == 'e')
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(80) << " " << endl;
        cout << setfill(' ');

        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            cout << endl;
        }
    }
    else if (kint == 'f')
    {
        ofstream fr(CRfv);
        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        fr << setfill('-') << setw(80) << " " << endl;
        fr << setfill(' ');

        for (int i = 0; i < A.size(); i++)
        {
            fr << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            fr << endl;
        }
        fr.close();
    }
    else
        throw runtime_error("Netinkama ivestis!");
}