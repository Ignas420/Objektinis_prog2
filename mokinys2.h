#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <deque>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <stdexcept>
#include <list>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

// const char CDfv[] = "kursiokai.txt";
const char CDfv0[] = "studentai10000.txt";
const char CDfv1[] = "studentai100000.txt";
const char CDfv2[] = "studentai1000000.txt";

class Mokinys
{
private:
    string vardas;
    string pavarde;
    deque<int> ND;
    int egzaminas;
    double VID;
    double MED;

public:
    bool Patikrinimas(string kint);
    void Vidurkis(deque<Mokinys> &A);
    void Isvedimas(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
    void Isvedimas2(const deque<Mokinys> &A, int MOK_kiekis, string isvedimas);
    bool PagalVidurki(const Mokinys &a, const Mokinys &b);
    bool PagalMediana(const Mokinys &a, const Mokinys &b);
    bool PagalVarda(const Mokinys &a, const Mokinys &b);
    bool PagalPavarde(const Mokinys &a, const Mokinys &b);
    void Rikiavimas(deque<Mokinys> &Mokslinciai, deque<Mokinys> &Nuskriaustieji, deque<int> &IrasuSk);
    void GeneruotiFailus(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<int> &IrasuSk, deque<Mokinys> &A);
    void Skaitymas(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<int> &IrasuSk, string failas, deque<Mokinys> &A, int &temp);
    void StudentuRusiavimas(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);
    void StudentuRusiavimas2(deque<Mokinys> &Nuskriaustieji, deque<Mokinys> &Mokslinciai, deque<Mokinys> &A, deque<int> &IrasuSk, string failas, int &temp);
    int main();
};

#endif
