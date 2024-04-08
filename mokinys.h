#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <stdexcept>
#include <list>
#include <deque>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

// const char CDfv[] = "kursiokai.txt";
const char CDfv0[] = "studentai10000.txt";
const char CDfv1[] = "studentai100000.txt";
const char CDfv2[] = "studentai1000000.txt";

/* struct Mokinys
{
    string vardas;
    string pavarde;
    vector<int> ND;
    int egzaminas;
    double VID;
    double MED;
}; */
class Mokinys
{
private:
    string vardas;
    string pavarde;
    vector<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    // Constructor
    Mokinys() : egzaminas(0), VID(0), MED(0) {}

    // Destructor
    ~Mokinys() {}

    // Getter functions
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getND() const { return ND; }
    int getEgzaminas() const { return egzaminas; }
    double getVID() const { return VID; }
    double getMED() const { return MED; }

    // Setter functions
    void setVardas(const string &name) { vardas = name; }
    void setPavarde(const string &surname) { pavarde = surname; }
    void addND(int nd) { ND.push_back(nd); }
    void clearND() { ND.clear(); }
    void setEgzaminas(int exam) { egzaminas = exam; }
    void setVID(double vid) { VID = vid; }
    void setMED(double med) { MED = med; }
    //Funkcijos
    bool Patikrinimas(string kint);
    void Vidurkis(vector<Mokinys> &A);
    void Isvedimas(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const vector<Mokinys> &A, int MOK_kiekis, string isvedimas);
    bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    bool PagalMediana(const Mokinys &a, const Mokinys &b);
    bool PagalVarda(const Mokinys &a, const Mokinys &b);
    bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Rikiavimas(vector<Mokinys> &Mokslinciai, vector<Mokinys> &Nuskriaustieji, vector<int> &IrasuSk);
    void GeneruotiFailus(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<int> &IrasuSk, vector<Mokinys> &A);
    void Skaitymas(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<int> &IrasuSk, string failas, vector<Mokinys> &A, int &temp);
    void StudentuRusiavimas(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<Mokinys> &A, vector<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(vector<Mokinys> &Nuskriaustieji, vector<Mokinys> &Mokslinciai, vector<Mokinys> &A, vector<int> &IrasuSk, string failas, int &temp);
    int main();
};

#endif