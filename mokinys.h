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

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CDfv[] = "kursiokai.txt";
//const char CDfv[] = "studentai10000.txt";
//const char CDfv[] = "studentai100000.txt";
//const char CDfv[] = "studentai1000000.txt";

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
bool PagalVidurki(const Mokinys &a, const Mokinys &b);
bool PagalMediana(const Mokinys &a, const Mokinys &b);
bool PagalVarda(const Mokinys &a, const Mokinys &b);
bool PagalPavarde(const Mokinys &a, const Mokinys &b);

#endif