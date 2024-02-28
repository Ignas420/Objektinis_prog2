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
const char CDfv[] = "C:/programos/0.3/Objektinis_prog/kursiokai.txt";
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

#endif