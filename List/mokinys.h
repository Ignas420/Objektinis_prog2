#ifndef MOKINYS_H
#define MOKINYS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include <deque>
#include <cstring>

using namespace std;

const char CRfv[] = "rezultatai.txt";
const char CRfv2[] = "naujas_failas.txt";
const char CRfv3[] = "mokslinciai.txt";
const char CRfv4[] = "nuskriaustieji.txt";

//const char CDfv[] = "kursiokai.txt";
const char CDfv0[] = "studentai10000.txt";
const char CDfv1[] = "studentai100000.txt";
const char CDfv2[] = "studentai1000000.txt";

struct Mokinys
{
    string vardas;
    string pavarde;
    list<int> ND;
    int egzaminas;
    double VID;
    double MED;
};

#endif
