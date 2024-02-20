#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CDfv[] = "kursiokai.txt";
/* const char CDfv[] = "studentai10000.txt";
const char CDfv[] = "studentai100000.txt";
const char CDfv[] = "studentai1000000.txt"; */

struct Mokinys
{
    string vardas;
    string pavarde;
    vector<int> ND;
    int egzaminas;
    double VID;
    double MED;
};

bool Patikrinimas(string kint);
void Vidurkis(vector<Mokinys> &A);
void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis);

int main()
{
    int n, m, kint;
    vector<Mokinys> A;
    ifstream fd(CDfv);
    string eil;
    char input;

    cout << "Norite ivesti, ar skaityti is failo?(i/s) ";
    cin >> input;

    if (input == 'i')
    {
        cout << "Irasykite kiek yra mokiniu: ";
        cin >> m;
        cout << "Iveskite vardus ir pavardes: " << endl;
        kint = m;
        Mokinys temp;
        while (m != 0)
        {
            cin >> temp.vardas >> temp.pavarde;
            if (!Patikrinimas(temp.vardas) || !Patikrinimas(temp.pavarde))
            {
                cout << "Ivestas netinkamas vardas arba pavarde" << endl;
                return 0;
            }
            A.push_back(temp);
            m--;
        }
        cout << "Irasykite namu darbu kieki: " << endl;
        cin >> n;
        kint = n;

        for (int i = 0; i < A.size(); i++) {
    cout << "Irasykite namu darbu pazymius: " << endl;
    for (int j = 0; j < n; j++) {
        int pazymys;
        cin >> pazymys;
        A[i].ND.push_back(pazymys);
        if (cin.fail()) {
            cout << "Namu darbai turi buti skaicius!" << endl;
            return 0;
        }
        if (pazymys < 1 || pazymys > 10) {
            cout << "Pazymys turi buti desimtbaleje sistemoje!";
            return 0;
        }
    }
    cout << "Irasykite egzamino rezultata: " << endl;
    cin >> A[i].egzaminas;
    if (cin.fail()) {
        cout << "Pazymys turi buti skaicius!" << endl;
        return 0;
    }
    if (A[i].egzaminas < 1 || A[i].egzaminas > 10) {
        cout << "Pazymys turi buti desimtbaleje sistemoje!";
        return 0;
    }
    Vidurkis(A);
    
    sort(A[i].ND.begin(), A[i].ND.end());

    vector<int> temp = A[i].ND;
    temp.push_back(A[i].egzaminas);
    sort(temp.begin(), temp.end());
    double median = temp[temp.size() / 2];
    if (temp.size() % 2 == 0)
        median = (temp[temp.size() / 2 - 1] + temp[temp.size() / 2]) / 2.0;
    A[i].MED = median;
}
    }
    else if (input == 's')
    {
        while (getline(fd, eil))
        {
            istringstream iss(eil);
            Mokinys temp;
            iss >> temp.vardas >> temp.pavarde;
            int pazymiai;
            while (iss >> pazymiai)
                temp.ND.push_back(pazymiai);

            if (!temp.ND.empty())
            {
                temp.egzaminas = temp.ND.back();
                temp.ND.pop_back();
            }

            sort(temp.ND.begin(), temp.ND.end());
            double mediana;

            if (!temp.ND.empty())
            {
                mediana = temp.ND[temp.ND.size() / 2];
                if (temp.ND.size() % 2 == 0)
                {
                    mediana = (temp.ND[temp.ND.size() / 2 - 1] + temp.ND[temp.ND.size() / 2]) / 2.0;
                }
            }
            temp.MED = mediana;
            A.push_back(temp);
        }
        fd.close();
        Vidurkis(A);
    Isvedimas(A, A.size());
    return 0;
}
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
void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis)
{
    char kint;
    cout << "Rezultatus matyti norite ekrane ar faile?(e/f): ";
    cin >> kint;
    if (kint == 'e')
    {
        cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(80) << " " << endl;
        cout << setfill(' ');

        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            cout << endl;
        }
    }
    else
    {
        ofstream fr(CRfv);
        fr << setw(20) << left << "Vardas" << setw(20) << left << "Pavardė" << setw(20) << right << "Galutinis (Vid.) / Galutinis(Med.)" << endl;
        fr << setfill('-') << setw(80) << " " << endl;
        fr << setfill(' ');

        for (int i = 0; i < A.size(); i++)
        {
            fr << setw(20) << left << A[i].vardas << setw(20) << left << A[i].pavarde << right << fixed << setprecision(2) << A[i].VID << setw(18) << right << A[i].MED;
            fr << endl;
        }
        fr.close();
    }
}
